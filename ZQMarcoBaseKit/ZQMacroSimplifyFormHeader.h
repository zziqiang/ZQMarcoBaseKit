//
//  ZQMacroSimplifyFormHeader.h
//  Client
//
//  Created by apple on 2019/12/20.
//  Copyright © 2019 apple. All rights reserved.
//

#ifndef ZQMacroSimplifyFormHeader_h
#define ZQMacroSimplifyFormHeader_h
#import "ZQMacroSupportTools.h"
#import "ZQMacroDeviceHeader.h"
#pragma mark - 一些重要缩写

#define kApplication        [UIApplication sharedApplication]

//依然会报警告
//#define kWindow (kiOS13Later ? [[[UIApplication sharedApplication] windows] objectAtIndex:0] : [UIApplication sharedApplication].keyWindow)

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_13_0
#define kWindow [[[UIApplication sharedApplication] windows] objectAtIndex:0]
#else
#define kWindow [UIApplication sharedApplication]
#endif

#define kAppDelegate        [UIApplication sharedApplication].delegate
#define kUserDefaults       [NSUserDefaults standardUserDefaults]
#define kNotificationCenter [NSNotificationCenter defaultCenter]
#define kScreenW            [UIScreen mainScreen].bounds.size.width       //屏幕宽度
#define kScreenH            [UIScreen mainScreen].bounds.size.height      //屏幕高度

#pragma mark - property

//常规对象
#define proNSString(str)                @property (nonatomic,copy)   NSString *str;
#define proNSArray(arr)                 @property (nonatomic,retain) NSArray *arr;
#define proNSMutableArray(arr)          @property (nonatomic,strong) NSMutableArray *arr;
#define proNSDictionary(dic)            @property (nonatomic,strong) NSDictionary *dic;
#define proNSMutableDictionary(dic)     @property (nonatomic,strong) NSMutableDictionary *dic;

//基本数据类型
#define proNSInteger(value)             @property(nonatomic, assign) NSInteger value;
#define proCGFloat(value)               @property(nonatomic, assign) CGFloat value;
#define proDouble(value)                @property(nonatomic, assign) double value;
#define proBool(value)                  @property(nonatomic, assign) BOOL value;

//指定类型
#define proNSMutableArrayType(type,arr) @property (nonatomic,strong) NSMutableArray <type * >*arr;
#define proCopyType(type,name)          @property (nonatomic,copy)   type *name;
#define proStrongType(type,name)        @property (nonatomic,strong) type *name;
#define proAssignType(type,name)        @property (nonatomic,assign) type name;

// 常用
#pragma mark - 常用

#define weakSelf(self)  __weak typeof(self)weakSelf = self;                       //弱引用
#define FM_IMAGE(str)            [UIImage imageNamed:(str)]                       //image
#define FM_STR_Int(value)      [NSString stringWithFormat:@"%ld",value]         //整数转字符串
#define FM_STR(id)               [NSString stringWithFormat:@"%@",id]             //转字符串
#define FM_URL(str)    [NSURL URLWithString:[ZQMacroSupportTools isContainChinese:str] ? [str stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet URLQueryAllowedCharacterSet]] : str]
//数据验证
#define StrValid(str) (str!=nil && [str isKindOfClass:[NSString class]] && ![str isEqualToString:@""])
#define SafeStr(str) (StrValid(str) ? str:@"")

#define kNavTitle(text)                 self.navigationItem.title = text;
#define kAllocInitVC(objc)              objc *vc = [[objc alloc] init];
#define kAllocInit(objc,name)           objc *name = [[objc alloc] init];
#define kAllocViewControllerByStr(objc) UIViewController *vc = [[NSClassFromString(objc) alloc] init];
#define kPushToTheViewController(vc)    [self.navigationController pushViewController:vc animated:YES];
#define kPopViewControllerWithAnimated  [self.navigationController popViewControllerAnimated:YES];

//单例 宏
#define singletonInterface  + (instancetype)sharedInstance;

#define singletonImplement(class) \
\
static class *_sharedInstance; \
\
+ (instancetype)sharedInstance { \
\
    if(_sharedInstance == nil) {\
        _sharedInstance = [[class alloc] init]; \
    } \
    return _sharedInstance; \
} \
\
+(instancetype)allocWithZone:(struct _NSZone *)zone { \
\
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
        _sharedInstance = [super allocWithZone:zone]; \
    }); \
\
    return _sharedInstance; \
\
}\
\
- (id)copyWithZone:(NSZone *)zone {\
\
    return _sharedInstance;\
}\
\
- (id)mutableCopyWithZone:(NSZone *)zone {\
    return _sharedInstance;\
}

#pragma mark - Log
//
#ifdef DEBUG
#define NSLog(format, ...) printf("class: < %s:(Line %d) > method: %s \n%s\n\n", [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, __PRETTY_FUNCTION__, [[NSString stringWithFormat:(format), ##__VA_ARGS__] UTF8String] );
#define ZQLog(format, ...) printf("class: < %s:(Line %d) > method: %s \n%s\n\n", [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, __PRETTY_FUNCTION__, [[NSString stringWithFormat:(format), ##__VA_ARGS__] UTF8String] );

#else
#define NSLog(...)
#define ZQLog(...)

#endif

#endif /* ZQMacroSimplifyFormHeader_h */
