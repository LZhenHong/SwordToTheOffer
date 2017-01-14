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
