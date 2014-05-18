//
//  GBThriftApi.h
//  GBThriftApi
//
//  Created by Luka Mirosevic on 18/05/2014.
//  Copyright (c) 2014 Goonbee. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^GBThriftCallCompletionBlock)(int status, id result, BOOL cancelled);

@interface GBThriftApi : NSObject

/**
 * Returns a singleton for the API library.
 */
+(instancetype)sharedApi;

/**
 * Opens a connection to the server.
 * You must call this method before making any API calls.
 */
-(void)connectToServer:(NSString *)server port:(NSUInteger)port;

/**
 * Subclasses should write beautiful idiomatic calls which then internally call this method which executes the actual call and does all the magic for error handling, automatic retries, etc.
 */
-(void)callAPIMethodWithSelector:(SEL)selector block:(GBThriftCallCompletionBlock)block arguments:(void *)argument, ... NS_REQUIRES_NIL_TERMINATION;

/**
 * The return value of this method is used to instantiate the thrift class.
 * Subclasses must override this method and return the class which implements the thrift service which they are implementing.
 */
+(Class)thriftServiceClass;

@end


//lm need automatic reconnection to server if something goes wrong, with request queing and backoff
//lm need to implement cancellation
