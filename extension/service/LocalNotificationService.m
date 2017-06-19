//
//  LocalNotificationService.m
//  EOSFramework
//
//  Created by Sam Chang on 5/28/14.
//  Copyright (c) 2014 HP. All rights reserved.
//

#import "LocalNotificationService.h"

@implementation LocalNotificationService

+(void)load{
    [[ESRegistry getInstance] registerService: @"LocalNotificationService" withName: @"localnotification"];
}

-(BOOL)singleton{
    return YES;
}

- (void) clear {
    [[UIApplication sharedApplication] cancelAllLocalNotifications];
}

- (BOOL) add: (NSDictionary *) dic{
    if (![dic isKindOfClass: [NSDictionary class]]) {
        return NO;
    }
    
    UILocalNotification *n = [[UILocalNotification alloc] init];
    if ([[dic valueForKey: @"sound"] isKindOfClass: [NSString class]]) {
        n.soundName = [dic valueForKey: @"sound"];
    }
    if ([[dic valueForKey: @"title"] isKindOfClass: [NSString class]]) {
        n.alertBody = [dic valueForKey: @"title"];
    }
    if ([[dic valueForKey: @"action"] isKindOfClass: [NSString class]]) {
        n.alertAction = [dic valueForKey: @"action"];
    }
    if ([[dic valueForKey: @"body"] isKindOfClass: [NSDictionary class]]) {
        n.userInfo = [dic valueForKey: @"body"];
    }
    if ([[dic valueForKey: @"datetime"] isKindOfClass: [NSNumber class]]) {
        n.fireDate = [NSDate dateWithTimeIntervalSince1970: [[dic valueForKey: @"datetime"] doubleValue]];
    }
    
    [[UIApplication sharedApplication] scheduleLocalNotification: n];
    return YES;
}

-(LuaTable *)toLuaTable{
    LuaTable *tb = [[LuaTable alloc] init];
    [tb.map setValue: UILocalNotificationDefaultSoundName forKey: @"defaultSound"];
    return tb;
}

@end
