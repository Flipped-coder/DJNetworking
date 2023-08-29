//
//  DJUserNetworking.m
//  DJNetworking
//
//  Created by 邓杰 on 2023/8/28.
//

#import "DJUserNetworking.h"
#import <AFNetworking/AFNetworking.h>
#import "DJNetworkConfig.h"

@implementation DJUserNetworking


@end


@implementation DJUserManageNetworking

/// 手机号 / 验证码登录
+ (void)phoneVerifyCodeLoginWithPhoneNumber:(NSString *)phoneNumber
                           verificationCode:(NSString *)verificationCode
                                  loginInfo:(DJLoginInfo *)loginInfo
                                 serverInfo:(DJServerInfo *)serverInfo
                          completionHandler:(DJNetworkingHandler)handler {
    
    
}


/// 手机号 / 密码登录
+ (void)phonePasswordLoginWithPhoneNumber:(NSString *)phoneNumber
                                 password:(NSString *)password
                                loginInfo:(DJLoginInfo *)loginInfo
                               serverInfo:(DJServerInfo *)serverInfo
                        completionHandler:(DJNetworkingHandler)handler {
    
    
}


/// 邮箱 / 验证码登录
+ (void)emailVerifyCodeLoginWithEmail:(NSString *)email
                     verificationCode:(NSString *)verificationCode
                            loginInfo:(DJLoginInfo *)loginInfo
                           serverInfo:(DJServerInfo *)serverInfo
                    completionHandler:(DJNetworkingHandler)handler {
    
    
    
}


/// 邮箱 / 密码登录
+ (void)emailPasswordLoginWithEmail:(NSString *)email
                           password:(NSString *)password
                          loginInfo:(DJLoginInfo *)loginInfo
                         serverInfo:(DJServerInfo *)serverInfo
                  completionHandler:(DJNetworkingHandler)handler {
    
    
}


/// ttk_ID / 密码登录
+ (void)ttkIDPasswordLoginWithTTKID:(NSString *)ttkID
                           password:(NSString *)password
                          loginInfo:(DJLoginInfo *)loginInfo
                         serverInfo:(DJServerInfo *)serverInfo
                  completionHandler:(DJNetworkingHandler)handler {
    
    
}



/// 第三方登录
+ (void)thirdPartyLoginWithToken:(NSString *)token
                       loginType:(DJLoginPathway *)loginType
                       loginInfo:(DJLoginInfo *)loginInfo
                      serverInfo:(DJServerInfo *)serverInfo
               completionHandler:(DJNetworkingHandler)handler {
    
    // 创建 AFHTTPSessionManager 对象
    AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
    
    // 设置请求格式为 JSON
    manager.requestSerializer = [AFJSONRequestSerializer serializer];
 
    // 发起 GET 请求
    [manager GET:serverInfo->api
      parameters:serverInfo->parameters
         headers:serverInfo->parameters
        progress:nil
         success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
             // 请求成功处理
             NSLog(@"Response: %@", responseObject);
         }
         failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
             // 请求失败处理
             NSLog(@"Error: %@", error);
         }];
}


// 第三方登录（备用接口）
+ (void)standbyThirdPartyLoginWithToken:(NSString *)token
                              loginType:(DJLoginPathway *)loginType
                              loginInfo:(DJLoginInfo *)loginInfo
                             serverInfo:(DJServerInfo *)serverInfo
                      completionHandler:(DJNetworkingHandler)handler {
    
    
    
}





@end
