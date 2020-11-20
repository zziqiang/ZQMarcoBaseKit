//
//  ZQMacroDeviceHeader.h
//  Client
//
//  Created by apple on 2019/12/20.
//  Copyright © 2019 apple. All rights reserved.
//

#ifndef ZQMacroDeviceHeader_h
#define ZQMacroDeviceHeader_h
#import "ZQMacroSupportTools.h"

#pragma mark - 判断系统版本 应用版本
//获得手机iOS版本
#define kSystemVersion  [[UIDevice currentDevice].systemVersion doubleValue]
//获得应用版本
#define kAppVersionCode ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"])

#define kiOSAvailableVersion(version) @available(iOS version, *)
#define kiOS9Later  kiOSAvailableVersion(9.0)
#define kiOS13Later kiOSAvailableVersion(13.0)
#define kiOS14Later kiOSAvailableVersion(14.0)

// iPhone 手机型号
#pragma mark - iPhone 手机型号

// 判断是否是 ipad
#define kIsPad ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)

// 判断 iPhone6系列 kIsiPhone_6_6s_7_8
#define kIsiPhone_6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)

// 判断iphone6P系列 kiIsPhone_6p_6sp_7p_8p
#define kIsiPhone_6P ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)

// 判断iPhoneX XS 11Pro
#define kIsPhone_X ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)

// 判断iPhoneXr iPhone11
#define kIsiPhone_XR ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size) : NO)

// 判断iPhoneXSMax iPhone11PorMax
#define kIsiPhone_XSMAX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size) : NO)

// 判断iPhone12Mini
#define kIsiPhone_12mini ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1080, 2340), [[UIScreen mainScreen] currentMode].size) : NO)

// 判断iPhone12 12Pro
#define kIsiPhone_12 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1170, 2532), [[UIScreen mainScreen] currentMode].size) : NO)

// 判断iPhone12ProMax
#define kIsiPhone_12ProMax ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1284, 2778), [[UIScreen mainScreen] currentMode].size) : NO)


/// 是否是iPhonex系列手机
#define kIsiPhoneXSeries (([ZQMacroSupportTools isNotchScreen]) ? YES : NO)

#endif /* ZQMacroDeviceHeader_h */
