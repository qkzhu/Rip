/*
 *  Copyright (C) 2007 - 2009 Stephen F. Booth <me@sbooth.org>
 *  All Rights Reserved
 */

#import <Cocoa/Cocoa.h>
#include <DiskArbitration/DiskArbitration.h>

@class CompactDisc, DriveInformation;
@class MetadataViewController, ExtractionViewController;

// ========================================
// The main window representing a single compact disc
// ========================================
@interface CompactDiscWindowController : NSWindowController
{
	IBOutlet NSView *_mainView;
	
@private
	__strong DADiskRef _disk;
	CompactDisc *_compactDisc;
	DriveInformation *_driveInformation;
	
	NSOperationQueue *_operationQueue;
	
	BOOL _extracting;
	
	MetadataViewController *_metadataViewController;
	ExtractionViewController *_extractionViewController;
}

// ========================================
// Properties
@property (assign) DADiskRef disk;

@property (readonly, assign) CompactDisc * compactDisc;
@property (readonly, assign) DriveInformation * driveInformation;

@property (readonly, assign, getter = isExtracting) BOOL extracting;

@property (readonly, assign) MetadataViewController * metadataViewController;
@property (readonly, assign) ExtractionViewController * extractionViewController;

// ========================================
// Action Methods
- (IBAction) selectAllTracks:(id)sender;
- (IBAction) deselectAllTracks:(id)sender;

- (IBAction) determineDriveReadOffset:(id)sender;

- (IBAction) copySelectedTracks:(id)sender;
- (IBAction) copyImage:(id)sender;

- (IBAction) detectPregaps:(id)sender;

- (IBAction) readMCN:(id)sender;
- (IBAction) readISRCs:(id)sender;

- (IBAction) createCueSheet:(id)sender;

- (IBAction) queryDefaultMusicDatabase:(id)sender;
- (IBAction) queryMusicDatabase:(id)sender;

- (IBAction) submitToDefaultMusicDatabase:(id)sender;
- (IBAction) submitToMusicDatabase:(id)sender;

- (IBAction) queryAccurateRip:(id)sender;

- (IBAction) ejectDisc:(id)sender;

@end
