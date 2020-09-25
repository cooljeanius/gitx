//
//  PBDetailController.h
//  GitX
//
//  Created by Pieter de Bie on 16-06-08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "PBGitRepository.h"

@class PBViewController;
@interface PBGitWindowController : NSWindowController {
#if __has_feature(objc_arc) || __has_feature(objc_arc_weak)
    PBGitRepository* repository;
#else /* GC: */
	__weak PBGitRepository* repository;
#endif
	int selectedViewIndex;
	IBOutlet NSView* contentView;

	PBViewController *historyViewController;
	PBViewController *commitViewController;

	PBViewController* viewController;
}

#if __has_feature(objc_arc) || __has_feature(objc_arc_weak)
@property (assign) PBGitRepository *repository;
#else /* GC: */
@property (assign) __weak PBGitRepository *repository;
#endif
@property (readonly) NSViewController *viewController;
@property (assign) int selectedViewIndex;

- (id)initWithRepository:(PBGitRepository*)theRepository displayDefault:(BOOL)display;

- (void)changeViewController:(NSInteger)whichViewTag;
- (void)useToolbar:(NSToolbar *)toolbar;
- (void)showMessageSheet:(NSString *)messageText infoText:(NSString *)infoText;
- (void)showErrorSheet:(NSError *)error;

- (IBAction) showCommitView:(id)sender;
- (IBAction) showHistoryView:(id)sender;
@end
