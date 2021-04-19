/*
Copyright (c) 2021 Chiu Yen-Chen, Swen Sun-Yen, Wen Yong-Wei.
All rights reserved.
Use of this source code is governed by a BSD-style license that can be
found in the LICENSE file. See the AUTHORS file for names of contributors.
 */

#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <memory>
#include <mutex>
#include <unordered_map>

#include "SURLCreator.h"

namespace shortlink {
	// Database save the look-up table to link each SURL to there original URL
	//
	// User can only do creating and reading the data.
	// In create operation:
	//		Data not exist: call insert operation.
	//		Data exist: call update operation.
	//
	// public implement: Create, Read
	// Create:		// if rawURL already exist, do UpdateSURL, else
	// InsertSURL
	//		string raw_url = "www.google.com"
	//		string short_url = "";
	//		string createStatus = database.CreateSURL(raw_url);
	//		if (createStatus != "")
	//			short_url = createStatus;
	//	Read:
	//		string raw_url = "";
	//		string findStatus = database.ReadSURL(short_url);
	//		if (findStatus != "")
	//			raw_url = findStatus;

	class Database {
	public:
		Database();

		// delete copy constructor
		Database(const Database&) = delete;

		// delete copy operator
		Database& operator=(const Database&) = delete;

		// lock the mutex when it is inserting.
		// There is only one inserting in the same time.
		bool InsertSURL(std::unique_ptr<SURL> surl);

		// Input a rawURL, return SURL if create is successful. Return "" if create
		// fail. Encode the rawURL to SURL and check whether it exists. If it exists
		// update expire time, else create the URL.
		std::string CreateSURL(const std::string& raw_url);

		// Read the lut whether URL exists. Return rawURL if SURL exists. Return "" if
		// SURL doesn't exist.
		std::string ReadSURL(const std::string& surl) const;

	private:
		// If there is a rawURL which encoding to a SURL that exists in LUT,
		// Update its expire time and don't need to create new one in LUT.
		bool UpdateSURL(std::unique_ptr<SURL> surl, Date expire);

		// It is for daily work. Check if the expire time of the SURL is over.
		bool CheckSURLExpiration();

		// If the expire time of the SURL is over, erase if in lut.
		bool DeleteSURL();

		// Encode the rawURL to the SURL and set the expire time to now.
		static std::unique_ptr<SURL> EncodeSURL(const std::string& raw_url);

		// The look up table of the SURL. Use SURL as key to find the original url.
		std::unordered_map<std::string, std::unique_ptr<SURL>> lut;

		// Lock to prevent multiple user from modifying the SURL.
		// There is only one insertion in the same time.
		std::mutex write_Lock;
	};
} // namespace shortlink

#endif
