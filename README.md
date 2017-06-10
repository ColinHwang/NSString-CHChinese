# NSString-CHChinese [![License MIT](https://img.shields.io/badge/license-MIT-green.svg?style=flat)](https://raw.githubusercontent.com/colinhwang/NSString-CHChinese/master/LICENSE)&nbsp;
Category methods of NSString to handle Chinese.

## Installation
### Manually
1. Download all the files in the NSString-CHChinese subdirectory.
2. Add the source files to your Xcode project.

## Usage
``` objc
#import "NSString+CHChinese.h"
```
### Chinese Type 
``` objc
typedef NS_OPTIONS(NSUInteger, CHNSStringChineseType) {   // Chinese Type 
    CHNSStringChineseTypeCharacter              = 1 << 0, // Chinese Character 
    CHNSStringChineseTypePunctuation            = 1 << 1, // Chinese Punctuation 
    CHNSStringChineseTypeRadical                = 1 << 2, // Chinese Radical 
    CHNSStringChineseTypeStroke                 = 1 << 3, // Chinese Stroke 
    CHNSStringChineseTypeIdeographicDescription = 1 << 4, // Chinese Ideographic Description 
    CHNSStringChineseTypeAll = CHNSStringChineseTypeCharacter | CHNSStringChineseTypePunctuation | CHNSStringChineseTypeRadical | CHNSStringChineseTypeStroke | CHNSStringChineseTypeIdeographicDescription
};
```
### Check Chinese
``` objc
BOOL isChinese = [string ch_isChinese:CHNSStringChineseTypeAll];

BOOL isContained = [string ch_containsChinese:CHNSStringChineseTypeCharacter|CHNSStringChineseTypePunctuation];
```
### Chinese Substring
``` objc
NSString *substring = [string ch_substringWithChinese:CHNSStringChineseTypeAll inRange:range];
```
### Enumerate Chinese 
``` objc
[string ch_enumerateChinese:CHNSStringChineseTypeAll inRange:range usingBlock:^(NSString * _Nullable substring, NSRange substringRange, NSRange enclosingRange, BOOL * _Nonnull stop) {
                 
}];
```
### Replace Chinese 
``` objc
NSString *substring = [string ch_stringByReplacingChinese:CHNSStringChineseTypeAll withString:replacement];
```
### Trim Chinese
``` objc
NSString *substring = [string ch_stringByTrimmingChinese:CHNSStringChineseTypeAll];
```
## Requirements
This library requires `iOS 7.0+` and `Xcode 7.0+`.

## License
NSString-CHChinese is provided under the MIT license. See LICENSE file for details.

## More
http://www.colinhwang.com/2017/06/09/handle-chinese

<br/><br/>
# 中文介绍
NSString分类方法，对于中文的一些处理。

## 安装
### 手动安装
1. 下载 NSString-CHChinese 文件夹内的所有内容。
2. 将 NSString-CHChinese 内的源文件添加到工程内。

## 用法
``` objc
#import "NSString+CHChinese.h"
```
### 中文类型
``` objc
typedef NS_OPTIONS(NSUInteger, CHNSStringChineseType) {   // Chinese Type 
    CHNSStringChineseTypeCharacter              = 1 << 0, // Chinese Character 
    CHNSStringChineseTypePunctuation            = 1 << 1, // Chinese Punctuation 
    CHNSStringChineseTypeRadical                = 1 << 2, // Chinese Radical 
    CHNSStringChineseTypeStroke                 = 1 << 3, // Chinese Stroke 
    CHNSStringChineseTypeIdeographicDescription = 1 << 4, // Chinese Ideographic Description 
    CHNSStringChineseTypeAll = CHNSStringChineseTypeCharacter | CHNSStringChineseTypePunctuation | CHNSStringChineseTypeRadical | CHNSStringChineseTypeStroke | CHNSStringChineseTypeIdeographicDescription
};
```
### 中文校验
``` objc
BOOL isChinese = [string ch_isChinese:CHNSStringChineseTypeAll];

BOOL isContained = [string ch_containsChinese:CHNSStringChineseTypeCharacter|CHNSStringChineseTypePunctuation];
```
### 截取中文
``` objc
NSString *substring = [string ch_substringWithChinese:CHNSStringChineseTypeAll inRange:range];
```
### 遍历中文 
``` objc
[string ch_enumerateChinese:CHNSStringChineseTypeAll inRange:range usingBlock:^(NSString * _Nullable substring, NSRange substringRange, NSRange enclosingRange, BOOL * _Nonnull stop) {
                 
}];
```
### 替换中文 
``` objc
NSString *substring = [string ch_stringByReplacingChinese:CHNSStringChineseTypeAll withString:replacement];
```
### 筛除中文
``` objc
NSString *substring = [string ch_stringByTrimmingChinese:CHNSStringChineseTypeAll];
```
## 系统要求
该项目最低支持 `iOS 7.0+` 和 `Xcode 7.0+`。

## 许可证
NSString-CHChinese 使用 MIT 许可证，详情见 LICENSE 文件。

## 更多
http://www.colinhwang.com/2017/06/09/handle-chinese
