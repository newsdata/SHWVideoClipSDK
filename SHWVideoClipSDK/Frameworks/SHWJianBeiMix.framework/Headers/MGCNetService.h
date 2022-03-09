//
//  MGCNetService.h
//  Runner
//
//  Created by Ray on 2020/2/25.
//  Copyright © 2020 The Chromium Authors. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MGCResponseInfo : NSObject
@property (nonatomic, assign) BOOL success;
@property (nonatomic, strong) NSString *code;
@property (nonatomic, strong) NSString *msg;
@property (nonatomic, strong) NSString *requestId;
@property (nonatomic, strong) id data;
@end

typedef void (^MGCResponseBlock) (MGCResponseInfo * _Nullable resp, NSError * _Nullable error);

@interface MGCNetService : NSObject

+ (instancetype)shareNetService;

- (void)getActionWithActionName:(NSString *)actionName
                         params:(NSDictionary *)params
                       complete:(MGCResponseBlock)complete;

- (void)postActionWithActionName:(NSString *)actionName
                          params:(NSDictionary *)params
                        complete:(MGCResponseBlock)complete;

@end

NS_ASSUME_NONNULL_END
