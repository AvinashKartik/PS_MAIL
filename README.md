# PS_MAIL
A GUI Local Email client that almost fully mimics an online email website, but locally within a computer. Of course, built entirely with Vanilla C++

The program, in very simple words, tries and replicates to an extent the job of any email client you can see in the internet. It is designed to allow the signed-up user to send and receive emails with the help of a graphical user interface. The program has been tested to work for different users within the same computer, across different computers in a LAN and is believed to work even in WAN.

---
## Categories
       USER

* The user is anyone who runs the program. Being a simple email client, it is programmed to not have a separate 'Admin' functionality, with an aim to protect every user's privacy.
The user can perform various tasks right from the start of the program. Initially the user can login or signup. The login portal asks the user his username and password. The signup portal asks the user his details to register himself into the program’s database. Once the user logs in, he or she encounters the GUI and deals with it from this point onwards.  The GUI now offers the user several option buttons. It includes the INBOX, SENTMAIL, SEARCH, DRAFTS, COMPOSE MAIL, and EXIT which can be accessed by the user at any point of time to swap between the functionality windows. Once the user logs in, by default the INBOX window opens which shows the user the list of emails he has received, with each row of the list box containing the from address, subject and time sent. Once the user clicks on the email he/she wants to view from the list box, he/she can see the contents of the email right below the list box. The SEARCH button swaps to a window which shows the user a list of names of the registered users. Once the user clicks a particular user’s name, he/ she is shown a list box like before, just containing the mails from that particular user alone, from which the user can select and view mails. The SENTMAIL button displays the mails received in a similar list box format as mentioned above and contains additional buttons REPLY and FORWARD whose functions are self-explanatory. The DRAFTS button shows the emails saved as drafts, again in a list box format. The COMPOSE MAIL button swaps to a window which has extra buttons: SEND, NEW and SAVE TO DRAFTS respectively. The functionality of these new buttons is self-explanatory. The window additionally contains three text areas to enter in respectively: the username, subject and body of the email. The user can send to multiple users at the same time. He/she is notified when there is no content, no subject or both or when an invalid username is entered. Once the user successfully sends an email, he/she is automatically redirected to the sent mail window. In addition to this, the program has a real-time notification box which constantly displays the no. of unread messages queued in the inbox. It is updated even when the user receives an email while he/she is logged in and performing any of the program’s tasks. The EXIT button is to quit the application. 

---
## Classes Used:
a. User_ID– 
* To perform various functions, with the main intention of storing user details.	

* Data Members: name, phno, age, pass1, pass2, uno
* Member functions: User_ID(), accept_signup(), accept_login(), accept_forgotpass(), void display(), and other acccessor and mutator functions to get and set most of the data members of the class.

b. Email_Box– 
* Data Members: sender, receiver, content, subject, content, eno, dt, read
* Member functions: Email_Box(const char*s, const char*r, const char* sub, const char* c), Email_Box(), void display(), get_total_inbox(), get_total_inbox(), get_total_sent1(), get_total_sent(), and other acccessor and mutator functions to get and set most of the data members of the class.


## Files Used:
    1) USER_DETAILS.dat-
A binary file. It contains the details of every single registered user. It is linked with class User_ID.

    2) EMAILS-SENT.dat -
A binary file. It consists every single email ever sent from one user to another. It is linked with class Email_Box.

## Limitations:

1. As of now, the GUI screen (programmed for a 1920*1080 screen resolution) does not resize its components for other screen resolutions. 

2. Under SEARCH, all existing users in the database are shown. In future, we are planning to restrict it and show only those with which a user has had ‘to and fro’ conversations.

3. No. of unread messages shows logical errors occasionally. This has to be rectified.
4. The user cannot send an email beyond a particular text limit. We have planned to get over this problem by using the help of heap memory in the future.
