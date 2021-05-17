/*
Copyright (c) 2021 Chiu Yen-Chen, Swen Sun-Yen, Wen Yong-Wei, Yuan Wei-Chen.
All rights reserved.
Use of this source code is governed by a BSD-style license that can be
found in the LICENSE file. See the AUTHORS file for names of contributors.
 */

#ifndef SHORTLINK_SRC_THREADPOOL_H_
#define SHORTLINK_SRC_THREADPOOL_H_
#include<vector>
#include<thread>

namespace shortlink
{
    //threah pool will create many threah at server inital
    //this class will handle thread operator
    //Example: 
    // ThreadPool threadpool = ThreadPool();
    // threadPool SetPoolSize(100);
    class ThreadPool
    {
    private:
        //maximum threads in this thread
        int max_pool_size;
        //current threads in this thread pool
        int cur_pool_size;
        //thread pool
        std::vector<std::thread> threads;

    public:
        //return how many unused thread in this class
        int GetFreePoolSize() const;
        //create more thread 
        void AddFreePool(const int& pool_size);
        //delete Free thread
        void RemoveFreePool(const int& pool_size);
        //delete thread that input
        void ReleaseThread(std::thread);
        //return Maxima thread size  in this class
        int GetMaxPoolSize() const;
        //return how many thread were using in this class
        int GetcurPoolSize() const;
        //set max pool size 
        void SetMaxPoolSize(const int& pool_size);
        //return a free thread
        const &std::thread GetThread();
    };
}// namespace shortlink

#endif  //SHORTLINK_SRC_THREADPOOL_H_
