//
//  main.m
//  单例 Objc
//
//  Created by LZhenHong on 2017/1/14.
//  Copyright © 2017年 lzh. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface Singleton: NSObject

+ (instancetype)sharedSingleton;

@end

@implementation Singleton

// 滥用单例之 dispatch_once 死锁
// https://satanwoo.github.io/2016/04/11/dispatch-once/
+ (instancetype)sharedSingleton {
    // 这里使用 GCD，注意两个 static。
    static Singleton *singleton = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        singleton = [[Singleton alloc] init];
    });
    return singleton;
}

@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
    }
    return 0;
}
