//
//  BPBaseRealmObject.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/17.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Realm/Realm.h>

/**
 Realm 数据库 model 基类
 
 Realm 支持的类型:
 - `NSString`
 - `NSInteger`, `int`, `long`, `float`, and `double`
 - `BOOL` or `bool`
 - `NSDate`
 - `NSData`
 - `NSNumber<X>`, where `X` is one of `RLMInt`, `RLMFloat`, `RLMDouble` or `RLMBool`, for optional number properties
 - `RLMObject` subclasses, to model many-to-one relationships.
 - `RLMArray<X>`, where `X` is an `RLMObject` subclass, to model many-to-many relationships.
 
 Realm对象的 Setters & Getters 不能被重载!!
 */
@interface BPBaseRealmObject : RLMObject

/// 用户 id
/// 会直接从 BPAccountManager 中取 currentUser，无需赋值
/// userID 为空时，表示当前为游客
@property NSString *userID;

#pragma mark - readonly

/// 主键 (默认值是 UUID)
@property NSString* primaryKey;

@end

