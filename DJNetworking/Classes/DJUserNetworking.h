//
//  DJUserNetworking.h
//  DJNetworking
//
//  Created by 邓杰 on 2023/8/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^DJNetworkingHandler)(id resultObject, NSError *error);

#pragma mark - Login_data 声明
/// 登录信息
typedef struct DJLoginInfo {
    /// 设备信息
    NSString *deviceInfo;
    /// 客户端信息（操作系统版本）
    NSString *clientInfo;
    /// 登录IP
    NSString *loginIp;
} DJLoginInfo;


#pragma mark - Login_type 声明
/// 登录途径
typedef NS_ENUM(NSUInteger, DJLoginPathway) {
  /// 第三方登录：Google
  DJGoogleLoginType    = 1,
  /// 第三方登录：Facebook
  DJFacebookLoginType  = 2,
  /// 第三方登录：Github
  DJGithubLoginType    = 3,
  /// 暂时未定义
  DJUserLogin_unkown1   = 4,
  /// 暂时未定义
  DJUserLogin_unkown2   = 5,
  /// 暂时未定义
  DJUserLogin_unkown3   = 6,
  /// 暂时未定义
  DJUserLogin_unkown4   = 7,
};


#pragma mark - 服务器配置信息
/// 服务器配置信息
typedef struct DJServerInfo {
    // 服务器 ip 地址
    NSString *ip;
    // 服务器端口号
    NSString *port;
    // 服务器路由
    NSString *route;
    // API
    NSString *api;
    // 请求头
    NSDictionary *headers;
    // 请求体
    NSDictionary *parameters;
    
} DJServerInfo;


#pragma mark - DJUser_Class 用户管理类(登录、登出、注册)

/**
 * 用户管理类
 * 主要包含用户登录、登出、注册等API
 */
@interface DJUserManageNetworking : NSObject


/**
 * @abstract 手机号/验证码 登录
 *
 * @param phoneNumber               手机号码
 * @param verificationCode    验证码
 * @param loginInfo                    登录设备信息
 * @param handler                        结果回调，返回当前登录用户的 Token
 */
+ (void)phoneVerifyCodeLoginWithPhoneNumber:(NSString *)phoneNumber
                           verificationCode:(NSString *)verificationCode
                                  loginInfo:(DJLoginInfo *)loginInfo
                                 serverInfo:(DJServerInfo *)serverInfo
                          completionHandler:(DJNetworkingHandler)handler;


/**
 * @abstract 手机/密码 登录
 *
 * @param phoneNumber                手机号码
 * @param password                       账号密码
 * @param loginInfo                    登录设备信息
 * @param handler                        结果回调，返回当前登录用户的 Token
 */
+ (void)phonePasswordLoginWithPhoneNumber:(NSString *)phoneNumber
                                 password:(NSString *)password
                                loginInfo:(DJLoginInfo *)loginInfo
                               serverInfo:(DJServerInfo *)serverInfo
                        completionHandler:(DJNetworkingHandler)handler;


/**
 * @abstract 邮箱/验证码 登录
 *
 * @param email                            用户邮箱
 * @param verificationCode    验证码
 * @param loginInfo                    登录设备信息
 * @param handler                        结果回调，返回当前登录用户的 Token
 */
+ (void)emailVerifyCodeLoginWithEmail:(NSString *)email
                     verificationCode:(NSString *)verificationCode
                            loginInfo:(DJLoginInfo *)loginInfo
                           serverInfo:(DJServerInfo *)serverInfo
                    completionHandler:(DJNetworkingHandler)handler;


/**
 * @abstract 邮箱/密码 登录
 *
 * @param email                            用户邮箱
 * @param password                     密码
 * @param loginInfo                   登录设备信息
 * @param handler                       结果回调，返回当前登录用户的 Token
 */
+ (void)emailPasswordLoginWithEmail:(NSString *)email
                           password:(NSString *)password
                          loginInfo:(DJLoginInfo *)loginInfo
                         serverInfo:(DJServerInfo *)serverInfo
                  completionHandler:(DJNetworkingHandler)handler;


/**
 * @abstract ttk_ID/密码 登录
 *
 * @param ttkID                            ttk_ID
 * @param password                     密码
 * @param loginInfo                   登录设备信息
 * @param handler                       结果回调，返回当前登录用户的 Token
 */
+ (void)ttkIDPasswordLoginWithTTKID:(NSString *)ttkID
                           password:(NSString *)password
                          loginInfo:(DJLoginInfo *)loginInfo
                         serverInfo:(DJServerInfo *)serverInfo
                  completionHandler:(DJNetworkingHandler)handler;


/**
 * @abstract 第三方登录
 *
 * @param token                            第三方平台token
 * @param loginType                   登录平台类型
 * @param loginInfo                   登录设备信息
 * @param handler                       结果回调，返回当前登录用户的 Token
 *
 * @discussion 由于网络原因，该方法在服务器上不一定成功，如果失败，则将自动调用下一个备用接口，以此获取ttk_token
 */
+ (void)thirdPartyLoginWithToken:(NSString *)token
                       loginType:(DJLoginPathway *)loginType
                       loginInfo:(DJLoginInfo *)loginInfo
                      serverInfo:(DJServerInfo *)serverInfo
               completionHandler:(DJNetworkingHandler)handler;


/**
 * @abstract 第三方登录（备用接口）
 *
 * @param token                            第三方平台token
 * @param loginType                   登录平台类型
 * @param loginInfo                   登录设备信息
 * @param handler                       结果回调，返回当前登录用户的 Token
 *
 * @discussion 该方法在本地请求第三方平台的用户数据，然后发往服务器，得到该用户的ttk_token
 */
+ (void)standbyThirdPartyLoginWithToken:(NSString *)token
                              loginType:(DJLoginPathway *)loginType
                              loginInfo:(DJLoginInfo *)loginInfo
                             serverInfo:(DJServerInfo *)serverInfo
                      completionHandler:(DJNetworkingHandler)handler;






@end





@interface DJUserNetworking : NSObject

@end

NS_ASSUME_NONNULL_END
