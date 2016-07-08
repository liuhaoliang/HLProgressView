//
//  HLProgressView.h
//  HLProgressViewDemo
//
//  Created by MrUncle on 15/3/3.
//  Copyright © 2015年 MrUncle. All rights reserved.
//



#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// Global
#define HLProgressViewDefaultStripeWidth 7 //px
#define HLProgressViewDefaultStripeDelta 8 //px

/**
 * The progress bar appearance.
 */
typedef NS_ENUM (NSUInteger, HLProgressViewType)
{
  /**
   * The progress bar has rounded corners and the gloss effect by default.
   */
  HLProgressViewTypeRounded = 0,
  /**
   * The progress bar has squared corners and no gloss.
   */
  HLProgressViewTypeFlat    = 1,
};

/**
 * The stripes orientation.
 */
typedef NS_ENUM (NSUInteger, HLProgressViewStripesOrientation)
{
  /**
   * The stripes are obliques in the north-west direction.
   */
  HLProgressViewStripesOrientationRight    = 0,
  /**
   * The stripes are obliques in the south-west direction.
   */
  HLProgressViewStripesOrientationLeft     = 1,
  /**
   * The stripes are verticals.
   */
  HLProgressViewStripesOrientationVertical = 2,
};

/**
 * The stripes movement direction.
 */
typedef NS_ENUM (NSInteger, HLProgressViewStripesDirection)
{
  /**
   * The stripes go from right to left.
   */
  HLProgressViewStripesDirectionLeft  = -1,
  /**
   * The stripes go from left to right.
   */
  HLProgressViewStripesDirectionRight = 1
};

/**
 * The behavior of a progress bar.
 */
typedef NS_ENUM (NSUInteger, HLProgressViewBehavior)
{
  /**
   * The default behavior of a progress bar. This mode is identical to the
   * UIProgressView.
   */
  HLProgressViewBehaviorDefault       = 0,
  /**
   * The indeterminate behavior display the stripes when the progress value is
   * equal to 0 only. This mode is helpful when percentage is not yet known,
   * but will be known shortly.
   */
  HLProgressViewBehaviorIndeterminate = 1,
  /**
   * The waiting behavior display the stripes when the progress value is equal
   * to 1 only.
   */
  HLProgressViewBehaviorWaiting       = 2,
};

/**
 * The display mode of the indicator text.
 */
typedef NS_ENUM (NSUInteger, HLProgressViewIndicatorTextDisplayMode)
{
  /**
   * The indicator text is not displayed.
   */
  HLProgressViewIndicatorTextDisplayModeNone     = 0,
  /**
   * The indicator text is displayed over the track bar and below the progress
   * bar.
   */
  HLProgressViewIndicatorTextDisplayModeTrack    = 1,
  /**
   * The indicator text is diplayed over the progress bar.
   */
  HLProgressViewIndicatorTextDisplayModeProgress = 2,
};

/**
 * The HLProgressView is an UIProgressView replacement with an highly and fully
 * customizable animated progress bar.
 *
 * The HLProgressView class provides properties for managing the style of the
 * track and the progress bar, managun its behavior and for getting and setting
 * values that are pinned to the progress of a task.
 *
 * Unlike the UIProgressView, the HLProgressView can be used for as an
 * indeterminate progress indicator thanks to its pre-made behaviors.
 *
 * <em>Note: The HLProgressView is conform to the UIAppearance protocol, however,
 * because of the current version of the appledoc project, the
 * UI_APPEARANCE_SELECTOR macros are not taken into account, that's why they
 * are commented.</em>
 */
IB_DESIGNABLE @interface HLProgressView : UIView

#pragma mark Managing the Progress Bar
/** @name Managing the Progress Bar */

/**
 * @abstract The current progress shown by the receiver.
 * @discussion The current progress is represented by a floating-point value
 * between 0.0 and 1.0, inclusive, where 1.0 indicates the completion of the
 * task.
 *
 * The default value is 0.3. Values less than 0.0 and greater than 1.0 are
 * pinned to those limits.
 */
@property (atomic, assign) IBInspectable CGFloat progress;

/**
 * @abstract Adjusts the current progress shown by the receiver, optionally
 * animating the change.
 * @param progress The new progress value.
 * @param animated YES if the change should be animated, NO if the change should
 * happen immediately.
 * @discussion The current progress is represented by a floating-point value
 * between 0.0 and 1.0, inclusive, where 1.0 indicates the completion of the
 * task.
 * The default value is 0.0. Values less than 0.0 and greater than 1.0 are
 * pinned to those limits.
 */
- (void)setProgress:(CGFloat)progress animated:(BOOL)animated;

#pragma mark Modifying the Progress Bar’s Behavior
/** @name Modifying the Progress Bar’s Behavior */

/**
 * @abstract The behavior of the progress bar.
 * A behavior defines how the progress bar needs to react in certain cases.
 * For example the "default" behavior of the progress bar displays the stripes
 * everytime whereas the "waiting" behavior displays them only when the
 * progress value is nearby the max value.
 *
 * @discussion The default value is HLProgressViewBehaviorDefault.
 */
@property (nonatomic, assign) IBInspectable HLProgressViewBehavior behavior; //UI_APPEARANCE_SELECTOR;

#pragma mark Configuring the Progress Bar
/** @name Configuring the Progress Bar */

/**
 * @abstract A Boolean value that determines whether the gloss effet (outer and
 * inner one) is hidden.
 * @discussion Setting the value of this property to YES hides the gloss effect
 * and setting it to NO shows the gloss effect whatever the progress type
 * (`HLProgressViewTypeRounded` or `HLProgressViewTypeFlat`). The value is updated
 * each time the type change.
 */
@property (nonatomic, assign) IBInspectable BOOL hideGloss;

/**
 * @abstract A Boolean value that determines whether the progress bar needs 
 * stretch when the value change.
 * @discussion Setting the value of this property to YES means that the colors
 * of the `progressTintColors` is stretched.
 *
 * For example the `progressTintColors` is equal to `[blue, yellow, red]` and
 * the `value` is set to 50%.
 * If the progress bar is stretch the progress bar looks like that:
 * `|-blue.yellow.red-----------|`
 * Otherwise it should looks like that:
 * `|-blue.....yellow-----------|`
 *
 * The default value is set to YES.
 */
@property (nonatomic, assign) IBInspectable BOOL progressStretch;

/**
 * @abstract The colors shown for the portion of the progress bar
 * that is filled.
 * @discussion All the colors in the array are drawn as a gradient
 * visual of equal size.
 */
@property (nonatomic, strong) NSArray *progressTintColors; //UI_APPEARANCE_SELECTOR;

/**
 * @abstract The color shown for the portion of the progress bar that is filled.
 */
@property (nonatomic, strong) IBInspectable UIColor *progressTintColor; //UI_APPEARANCE_SELECTOR;

/**
 * @abstract The color shown for the portion of the progress bar that is not
 * filled.
 */
@property (nonatomic, strong) IBInspectable UIColor *trackTintColor; //UI_APPEARANCE_SELECTOR;

/**
 * @abstract A CGFloat value that determines the inset between the track and the
 * progressBar for the rounded progress bar type.
 * @discussion The default value is 1px.
 */
@property (nonatomic, assign) IBInspectable CGFloat progressBarInset; //UI_APPEARANCE_SELECTOR;

/**
 * @abstract The type of the progress bar.
 * @discussion The default value is set to `HLProgressViewTypeRounded`. The corner 
 * radius can be configured through the `cornerRadius` property.
 */
@property (nonatomic, assign) IBInspectable HLProgressViewType type; //UI_APPEARANCE_SELECTOR;

/**
 * @abstract The corner radius of the progress bar.
 * @discussion The default value is 0. It means that the corner radius is equal
 * to the half of the height.
 */
@property (nonatomic, assign) IBInspectable CGFloat cornerRadius; //UI_APPEARANCE_SELECTOR;

/**
 * @abstract Animation time
 * @discussion The default value is 1.f
 */
@property (nonatomic, assign) IBInspectable NSTimeInterval progressBarProgressTime; //UI_APPEARANCE_SELECTOR;

#pragma mark Displaying Text
/** @name Displaying Text */

/**
 * @abstract A label to display some indications for the user.
 * When the label text is set to nil it shows the progress value as a percentage
 * You can configure its font color, the font size, the text alignement, etc. as
 * any other labels.
 * @discussion By default the label text is set to nil and its text color change
 * using the background color.
 */
@property (nonatomic, strong) UILabel *indicatorTextLabel;

/**
 * @abstract The display indicator text mode. It defines where the indicator
 * text needs to display.
 * @discussion The default value is set to
 * `HLProgressViewIndicatorTextDisplayModeNone`.
 */
@property (nonatomic, assign) IBInspectable HLProgressViewIndicatorTextDisplayMode indicatorTextDisplayMode; //UI_APPEARANCE_SELECTOR;

#pragma mark Configuring the Stripes
/** @name Configuring the Stripes */

/**
 * @abstract The animated vs. nonanimated stripes of the progress bar.
 * @discussion If YES, the stripes over the progress bar is moving from the left
 * to the right side.
 *
 * The default value for this property is YES.
 */
@property (nonatomic, getter = isStripesAnimated) IBInspectable BOOL stripesAnimated;

/**
 * @abstract The direction of the movement during the animation.
 * @discussion The default value for this property is
 * `HLProgressViewStripesDirectionRight`.
 */
@property (nonatomic, assign) IBInspectable HLProgressViewStripesDirection stripesDirection; //UI_APPEARANCE_SELECTOR;

/**
 * @abstract The velocity of the stripes during the animation. Higher is the
 * value, greater the distance traveled by the stripes during a frame is.
 * @discussion The absolute value of the property is taken into account. By
 * default the velocity is `1`.
 */
@property (nonatomic, assign) IBInspectable double stripesAnimationVelocity; //UI_APPEARANCE_SELECTOR;

/**
 * @abstract The orientation of the stripes.
 * @discussion The default value for this property is
 * `HLProgressViewStripesOrientationRight`.
 */
@property (nonatomic, assign) IBInspectable HLProgressViewStripesOrientation stripesOrientation; //UI_APPEARANCE_SELECTOR;

/**
 * @abstract The width of the stripes drawn over the progress bar.
 * @discussion If the property is less or equal than 0 the sprites are hidden.
 *
 * The default value for this property is equal to the
 * `HLProgressViewDefaultStripeWidth` value.
 */
@property (nonatomic, assign) IBInspectable NSInteger stripesWidth; //UI_APPEARANCE_SELECTOR;

/**
 * @abstract The color show for the stripes over the progress bar.
 */
@property (nonatomic, strong) IBInspectable UIColor *stripesColor; //UI_APPEARANCE_SELECTOR;

/**
 * @abstract The x-coordinate distance in pixels between the top point and the
 * bottom point of a slanted stripe.
 * @discussion Default value is `HLProgressViewDefaultStripeDelta`. Positive
 * integers are expected for correct effect. Has no effect when
 * stripesOrientation property is `HLProgressViewStripesOrientationVertical`.
 */
@property (nonatomic, assign) IBInspectable NSInteger stripesDelta; //UI_APPEARANCE_SELECTOR;

/**
 * @abstract A Boolean value that determines whether the stripes are hidden.
 * @discussion Setting the value of this property to YES hides the stripes and
 * setting it to NO shows the stripes. The default value is NO.
 */
@property (nonatomic, assign) IBInspectable BOOL hideStripes;

/**
 * @abstract A Boolean value that determines whether the track is hidden.
 * @discussion Setting the value of this property to YES hides the track and
 * setting it to NO shows the track. The default value is NO.
 */
@property (nonatomic, assign) IBInspectable BOOL hideTrack;

@end

//! Project version number for HLProgressView.
FOUNDATION_EXPORT double HLProgressViewVersionNumber;

//! Project version string for HLProgressView.
FOUNDATION_EXPORT const unsigned char HLProgressViewVersionString[];