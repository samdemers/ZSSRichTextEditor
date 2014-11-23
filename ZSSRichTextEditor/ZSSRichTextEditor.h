//
//  ZSSRichTextEditorViewController.h
//  ZSSRichTextEditor
//
//  Created by Nicholas Hubbard on 11/30/13.
//  Copyright (c) 2013 Zed Said Studio. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HRColorPickerViewController.h"

/**
 *  The types of toolbar items that can be added
 */
typedef NS_ENUM(NSUInteger, ZSSRichTextEditorToolbar) {
    ZSSRichTextEditorToolbarNone = 0,
    ZSSRichTextEditorToolbarBold = 1,
    ZSSRichTextEditorToolbarItalic = 1 << 1,
    ZSSRichTextEditorToolbarSubscript = 1 << 2,
    ZSSRichTextEditorToolbarSuperscript = 1 << 3,
    ZSSRichTextEditorToolbarStrikeThrough = 1 << 4,
    ZSSRichTextEditorToolbarUnderline = 1 << 5,
    ZSSRichTextEditorToolbarRemoveFormat = 1 << 6,
    ZSSRichTextEditorToolbarJustifyLeft = 1 << 7,
    ZSSRichTextEditorToolbarJustifyCenter = 1 << 8,
    ZSSRichTextEditorToolbarJustifyRight = 1 << 9,
    ZSSRichTextEditorToolbarJustifyFull = 1 << 10,
    ZSSRichTextEditorToolbarH1 = 1 << 11,
    ZSSRichTextEditorToolbarH2 = 1 << 12,
    ZSSRichTextEditorToolbarH3 = 1 << 13,
    ZSSRichTextEditorToolbarH4 = 1 << 14,
    ZSSRichTextEditorToolbarH5 = 1 << 15,
    ZSSRichTextEditorToolbarH6 = 1 << 16,
    ZSSRichTextEditorToolbarTextColor = 1 << 17,
    ZSSRichTextEditorToolbarBackgroundColor = 1 << 18,
    ZSSRichTextEditorToolbarUnorderedList = 1 << 19,
    ZSSRichTextEditorToolbarOrderedList = 1 << 20,
    ZSSRichTextEditorToolbarHorizontalRule = 1 << 21,
    ZSSRichTextEditorToolbarIndent = 1 << 22,
    ZSSRichTextEditorToolbarOutdent = 1 << 23,
    ZSSRichTextEditorToolbarInsertImage = 1 << 24,
    ZSSRichTextEditorToolbarInsertLink = 1 << 25,
    ZSSRichTextEditorToolbarRemoveLink = 1 << 26,
    ZSSRichTextEditorToolbarQuickLink = 1 << 27,
    ZSSRichTextEditorToolbarUndo = 1 << 28,
    ZSSRichTextEditorToolbarRedo = 1 << 29,
    ZSSRichTextEditorToolbarViewSource = 1 << 30,
    ZSSRichTextEditorToolbarParagraph = 1 << 31,
    ZSSRichTextEditorToolbarAll = ~0,
};

@class ZSSBarButtonItem;

/**
 *  The viewController used with ZSSRichTextEditor
 */
@interface ZSSRichTextEditor : UIViewController <UIWebViewDelegate, HRColorPickerViewControllerDelegate, UITextViewDelegate>


/**
 *  The base URL to use for the webView
 */
@property (nonatomic, strong) NSURL *baseURL;

/**
 *  If the HTML should be formatted to be pretty
 */
@property (nonatomic) BOOL formatHTML;

/**
 *  If the keyboard should be shown when the editor loads
 */
@property (nonatomic) BOOL shouldShowKeyboard;

/**
 *  The placeholder text to use if there is no editor content
 */
@property (nonatomic, strong) NSString *placeholder;

/**
 *  Toolbar items to include
 */
@property (nonatomic) ZSSRichTextEditorToolbar enabledToolbarItems;

/**
 *  Color to tint the toolbar items
 */
@property (nonatomic, strong) UIColor *toolbarItemTintColor;

/**
 *  Color to tint selected items
 */
@property (nonatomic, strong) UIColor *toolbarItemSelectedTintColor;

/**
 *  Sets the HTML for the entire editor
 *
 *  @param html  HTML string to set for the editor
 *
 */
- (void)setHTML:(NSString *)html;

/**
 *  Returns the HTML from the Rich Text Editor
 *
 */
- (NSString *)getHTML;

/**
 *  Returns the plain text from the Rich Text Editor
 *
 */
- (NSString *)getText;

/**
 *  Inserts HTML at the caret position
 *
 *  @param html  HTML string to insert
 *
 */
- (void)insertHTML:(NSString *)html;

/**
 *  Manually focuses on the text editor
 */
- (void)focusTextEditor;

/**
 *  Manually dismisses on the text editor
 */
- (void)blurTextEditor;

/**
 *  Shows the insert image dialog with optinal inputs
 *
 *  @param url The URL for the image
 *  @param alt The alt for the image
 */
- (void)showInsertImageDialogWithLink:(NSString *)url alt:(NSString *)alt;

/**
 *  Inserts an image
 *
 *  @param url The URL for the image
 *  @param alt The alt attribute for the image
 */
- (void)insertImage:(NSString *)url alt:(NSString *)alt;

/**
 *  Shows the insert link dialog with optional inputs
 *
 *  @param url   The URL for the link
 *  @param title The tile for the link
 */
- (void)showInsertLinkDialogWithLink:(NSString *)url title:(NSString *)title;

/**
 *  Inserts a link
 *
 *  @param url The URL for the link
 *  @param title The title for the link
 */
- (void)insertLink:(NSString *)url title:(NSString *)title;

/**
 *  Gets called when the insert URL picker button is tapped in an alertView
 *
 *  @warning The default implementation of this method is blank and does nothing
 */
- (void)showInsertURLAlternatePicker;

/**
 *  Gets called when the insert Image picker button is tapped in an alertView
 *
 *  @warning The default implementation of this method is blank and does nothing
 */
- (void)showInsertImageAlternatePicker;

/**
 *  Dismisses the current AlertView
 */
- (void)dismissAlertView;

/**
 *  Add a custom UIBarButtonItem by using a UIButton
 */
- (void)addCustomToolbarItemWithButton:(UIButton*)button;

/**
 *  Add a custom ZSSBarButtonItem
 */
- (void)addCustomToolbarItem:(ZSSBarButtonItem *)item;

/**
 *  Scroll event callback with position
 */
- (void)editorDidScrollWithPosition:(NSInteger)position;

@end
