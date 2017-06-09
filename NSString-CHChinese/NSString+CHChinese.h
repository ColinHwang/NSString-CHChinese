//
//  NSString-CHChinese.h
//  NSString-CHChinese
//
//  Created by colin on 17/6/2.
//  Copyright © 2017年 Colin. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, CHNSStringChineseType) {   // Chinese Type 中文字符类型
    CHNSStringChineseTypeCharacter              = 1 << 0, // Chinese Character 中文文字
    CHNSStringChineseTypePunctuation            = 1 << 1, // Chinese Punctuation 中文标点
    CHNSStringChineseTypeRadical                = 1 << 2, // Chinese Radical 中文部首
    CHNSStringChineseTypeStroke                 = 1 << 3, // Chinese Stroke 中文笔划
    CHNSStringChineseTypeIdeographicDescription = 1 << 4, // Chinese Ideographic Description 中文构字描述符
    CHNSStringChineseTypeAll = CHNSStringChineseTypeCharacter | CHNSStringChineseTypePunctuation | CHNSStringChineseTypeRadical | CHNSStringChineseTypeStroke | CHNSStringChineseTypeIdeographicDescription
};

@interface NSString (CHChinese)

/**
 Returns whether the receiver is a Chinese string(one-character) in the specified type.

 @param type The Chinese type. Pass 0 to specify all types.
 @return YES if the receiver is a Chinese string(one-character), otherwise NO.
 */
- (BOOL)ch_isChinese:(CHNSStringChineseType)type;

/**
 Returns whether the receiver contains a Chinese string in the specified type.

 @param type The Chinese type. Pass 0 to specify all types.
 @return YES if the receiver contains Chinese string, otherwise NO.
 */
- (BOOL)ch_containsChinese:(CHNSStringChineseType)type;

/**
 Returns a string object containing the Chinese string in the specified type of the receiver that lie within a given range.

 @param type The Chinese type. Pass 0 to specify all types.
 @param range A range. The range must not exceed the bounds of the receiver.
 @return A string object containing the Chinese string in the specified type of the receiver that lie within aRange.
 */
- (NSString *)ch_substringWithChinese:(CHNSStringChineseType)type inRange:(NSRange)range;

/**
 Enumerates the Chinese substrings of the specified type in the specified range of the string.

 @param type The Chinese type. Pass 0 to specify all types.
 @param range The range within the string to enumerate Chinese substrings.
 @param block The block executed for the enumeration. The block takes four arguments:
    substring: The enumerated string.
    substringRange: The range of the enumerated string in the receiver.
    enclosingRange: The range that includes the substring as well as any separator or filler characters that follow. For instance, for lines, enclosingRange contains the line terminators. The enclosingRange for the first string enumerated also contains any characters that occur before the string. Consecutive enclosing ranges are guaranteed not to overlap, and every single character in the enumerated range is included in one and only one enclosing range.
    stop: A reference to a Boolean value that the block can use to stop the enumeration by setting *stop = YES; it should not touch *stop otherwise.
 */
- (void)ch_enumerateChinese:(CHNSStringChineseType)type
                    inRange:(NSRange)range
                 usingBlock:(void (^)(NSString * _Nullable substring, NSRange substringRange, NSRange enclosingRange, BOOL *stop))block;

/**
 Returns a new string in which all Chinese string in the specified type are replaced by another given string.

 @param type The Chinese type. Pass 0 to specify all types.
 @param replacement The string with which to replace target.
 @return A new string in which all Chinese, matched using type, in the receiver are replaced by replacement.
 */
- (NSString *)ch_stringByReplacingChinese:(CHNSStringChineseType)type withString:(NSString *)replacement;

/**
 Returns a new string made by removing all Chinese string in the specified type  of the receiver.

 @param type The Chinese type. Pass 0 to specify all types.
 @return A new string made by removing all Chinese string in the specified type  of the receiver.
 */
- (NSString *)ch_stringByTrimmingChinese:(CHNSStringChineseType)type;

@end

NS_ASSUME_NONNULL_END
