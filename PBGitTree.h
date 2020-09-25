//
//  PBGitTree.h
//  GitTest
//
//  Created by Pieter de Bie on 15-06-08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "PBGitRepository.h"

@interface PBGitTree : NSObject {
	long long _fileSize;

	NSString* sha;
	NSString* path;
	PBGitRepository* repository;
#if __has_feature(objc_arc) || __has_feature(objc_arc_weak)
    PBGitTree* parent;
#else /* GC: */
	__weak PBGitTree* parent;
#endif
	NSArray* children;
	BOOL leaf;

	NSString* localFileName;
	NSDate* localMtime;
}

+ (PBGitTree*) rootForCommit: (id) commit;
+ (PBGitTree*) treeForTree: (PBGitTree*) tree andPath: (NSString*) path;
- (void) saveToFolder: (NSString *) directory;

- (NSString*) tmpFileNameForContents;
- (long long)fileSize;

@property(copy) NSString* sha;
@property(copy) NSString* path;
@property(assign) BOOL leaf;
@property(retain) PBGitRepository* repository;
#if __has_feature(objc_arc) || __has_feature(objc_arc_weak)
@property(assign) PBGitTree* parent;
#else /* GC: */
@property(assign) __weak PBGitTree* parent;
#endif

@property(readonly) NSArray* children;
@property(readonly) NSString* fullPath;
@property(readonly) NSString* contents;

@end
