//
//  ZQMacroSupportTools.m
//  Client
//
//  Created by apple on 2019/12/20.
//  Copyright © 2019 apple. All rights reserved.
//

#import "ZQMacroSupportTools.h"
#import <sys/utsname.h>

@implementation ZQMacroSupportTools

//内联函数 防止大量消耗栈空间
static inline NSUInteger fm_hexStrToInt(NSString *str) {
    uint32_t result = 0;
    sscanf([str UTF8String], "%x", &result);
    return result;
}


static BOOL fm_hexStrToRGBA(NSString *str, CGFloat *r, CGFloat *g, CGFloat *b, CGFloat *a) {
    str = [str uppercaseString];
    
    //解析起始点 对应不同的格式 # 0X 0x
    if ([str hasPrefix:@"#"]) {
        str = [str substringFromIndex:1];
    } else if ([str hasPrefix:@"0X"]) {
        str = [str substringFromIndex:2];
    } else if ([str hasPrefix:@"0x"]) {
        str = [str substringFromIndex:2];
    }
    
    NSUInteger length = [str length];
    //RGB  RGBA  RRGGBB  RRGGBBAA
    if (length != 3 && length != 4 && length != 6 && length != 8) {
        return NO;
    }
    
    //RGB,RGBA,RRGGBB,RRGGBBAA
    if (length < 5) {
        *r = fm_hexStrToInt([str substringWithRange:NSMakeRange(0, 1)]) / 255.0f;
        *g = fm_hexStrToInt([str substringWithRange:NSMakeRange(1, 1)]) / 255.0f;
        *b = fm_hexStrToInt([str substringWithRange:NSMakeRange(2, 1)]) / 255.0f;
        if (length == 4)  *a = fm_hexStrToInt([str substringWithRange:NSMakeRange(3, 1)]) / 255.0f;
        else *a = 1;
    } else {
        *r = fm_hexStrToInt([str substringWithRange:NSMakeRange(0, 2)]) / 255.0f;
        *g = fm_hexStrToInt([str substringWithRange:NSMakeRange(2, 2)]) / 255.0f;
        *b = fm_hexStrToInt([str substringWithRange:NSMakeRange(4, 2)]) / 255.0f;
        if (length == 8) *a = fm_hexStrToInt([str substringWithRange:NSMakeRange(6, 2)]) / 255.0f;
        else *a = 1;
    }
    return YES;
}

+ (UIColor *)colorWithHexString:(NSString *)color{
    CGFloat r, g, b, a;
    if (fm_hexStrToRGBA(color, &r, &g, &b, &a)) {
        return [UIColor colorWithRed:r green:g blue:b alpha:a];
    }
    return nil;
}

/// 判断刘海屏，返回YES表示是刘海屏
+ (BOOL)isNotchScreen {
    static BOOL isiPhoneX = NO;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        
#if TARGET_IPHONE_SIMULATOR
        // 获取模拟器所对应的 device model
        NSString *model = NSProcessInfo.processInfo.environment[@"SIMULATOR_MODEL_IDENTIFIER"];
#else
        // 获取真机设备的 device model
        struct utsname systemInfo;
        uname(&systemInfo);
        NSString *model = [NSString stringWithCString:systemInfo.machine encoding:NSUTF8StringEncoding];
#endif
        // 判断 device model 是否为 "iPhone10,3" 和 "iPhone10,6" 或者以 "iPhone11," "iPhone12,"开头 以后可以还会增加
        // 如果是，就认为是 刘海屏
        isiPhoneX = [model isEqualToString:@"iPhone10,3"] || [model isEqualToString:@"iPhone10,6"] || [model hasPrefix:@"iPhone11,"] || [model hasPrefix:@"iPhone12,"];
    });
    
    return isiPhoneX;
}


+ (BOOL)isContainChinese:(NSString *)url{
    NSUInteger length = [url length];
    for (NSUInteger i = 0; i < length; i++) {
        NSRange range = NSMakeRange(i, 1);
        NSString *subString = [url substringWithRange:range];
        const char *cString = [subString UTF8String];
        if (strlen(cString) == 3) {
            return YES;
        }
    }
    return NO;

}

@end
