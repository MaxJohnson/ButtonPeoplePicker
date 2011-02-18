//
//  ButtonPeoplePicker.h
//
//  Created by shrtlist.com
//

#import "ButtonPeoplePicker.h"
#import "AddPersonViewController.h"
#import <AddressBook/AddressBook.h>

@protocol ButtonPeoplePickerDelegate;

@interface ButtonPeoplePicker : UIViewController <AddPersonViewControllerDelegate,
												  UITableViewDataSource,
												  UITableViewDelegate,
												  UIKeyInput>
{
	id <ButtonPeoplePickerDelegate> delegate;

	IBOutlet UILabel *deleteLabel;
	IBOutlet UIView *buttonView;
	IBOutlet UITableView *tView;
	IBOutlet UITextField *searchField;
	
	UIButton *selectedButton;
	
	NSArray *people;
	NSMutableArray *filteredPeople;	// The content filtered as a result of a search.
	NSMutableArray *group;

	ABAddressBookRef addressBook;
}

@property (nonatomic, assign) id <ButtonPeoplePickerDelegate> delegate;
@property (nonatomic, retain) NSMutableArray *filteredPeople;
@property (nonatomic, retain) NSMutableArray *group;

-(IBAction)cancelClick:(id)sender;
-(IBAction)doneClick:(id)sender;
-(IBAction)buttonSelected:(id)sender;

-(void)layoutNameButtons;
-(void)addPersonToGroup:(NSDictionary *)personDictionary;
-(void)removePersonFromGroup:(NSDictionary *)personDictionary;
-(void)displayAddPersonViewController;

@end

@protocol ButtonPeoplePickerDelegate
- (void)buttonPeoplePickerDidFinish:(ButtonPeoplePicker *)controller;
@end