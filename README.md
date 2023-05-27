# Flexi-Pay-Online
OOP(C++) project with File Handling
# INTRODUCTION
It is a BKASH simulator,which is developed in C++. It shows aspects of online payment and transfer money like 𝒂𝒄𝒄𝒐𝒖𝒏𝒕 𝒄𝒓𝒆𝒂𝒕𝒊𝒐𝒏, 𝒕𝒓𝒂𝒏𝒔𝒂𝒄𝒕𝒊𝒐𝒏𝒂𝒍 𝒂𝒄𝒕𝒊𝒗𝒊𝒕𝒊𝒆𝒔, 𝑭𝒍𝒆𝒙𝒊𝒍𝒐𝒂𝒅, 𝒐𝒏𝒍𝒊𝒏𝒆 𝒑𝒂𝒚𝒎𝒆𝒏𝒕,𝒈𝒓𝒆𝒆𝒕𝒊𝒏𝒈 𝒊𝒏 𝒔𝒑𝒆𝒄𝒊𝒂𝒍 𝒐𝒄𝒄𝒂𝒔𝒊𝒐𝒏𝒔 𝒘𝒊𝒕𝒉 𝒎𝒆𝒔𝒔𝒂𝒈𝒆𝒔. The transactions & its date time and client information are kept in files and are accessed at a later time using the file handling concepts.
# WORKING
This program starts off with a  screen, there will be Menu with 4 options.𝑺𝑰𝑮𝑵 𝑼𝑷,𝑳𝑶𝑮 𝑰𝑵,𝑫𝑬𝑳𝑬𝑻𝑬 𝑨𝑪𝑪𝑶𝑼𝑵𝑻,𝑬𝑿𝑰𝑻. The program then becomes a menu-driven program which performs file management operations as long as the user decides to quit.
# DETAILS
The user is allowed to use the following operations:
•𝐒𝐈𝐆𝐍 𝐔𝐏          :This feature adds user to the system.users have to create account with unique phone number,name,4 digit PIN,initial ammount.if account exists with same number it can detect and refuses to create account.
•𝐋𝐎𝐆𝐈𝐍            :Users have to log in with account number aka phone number and PIN an can use following features:

									• 𝐃𝐄𝐏𝐎𝐒𝐈𝐓               : we can cash in money(BDT) in account.  
                  • 𝐓𝐑𝐀𝐍𝐒𝐅𝐄𝐑             : we can transfer money to another user
                  • 𝐕𝐈𝐄𝐖 𝐖𝐀𝐋𝐋𝐄𝐓         : we can observe how much money users have in their account.
                  • 𝐓𝐑𝐀𝐍𝐒𝐀𝐂𝐓𝐈𝐎𝐍 𝐇𝐈𝐒𝐓𝐎𝐑𝐘 : whenever we deposit,or transfer,recharge money or cash out or send geetings to others ,we can see the time and date of transaction.
									• 𝐌𝐎𝐁𝐈𝐋𝐄 𝐑𝐄𝐂𝐇𝐀𝐑𝐆𝐄     : we can recharge money online to any sim operator user in Banglidesh.There will be options Banglalink,Airtel,Teletalk bla bla.User has to choose option and then recharge .
									• 𝐂𝐀𝐒𝐇 𝐎𝐔𝐓             :the amount of money we have in account we can get in cash using this feature.For that user has to transfer the amount of money to the Agent.For the list of Agents there already exists a file named 𝐀𝐆𝐄𝐍𝐓.𝐭𝐱𝐭 .
									• 𝐎𝐍𝐋𝐈𝐍𝐄 𝐏𝐀𝐘𝐌𝐄𝐍𝐓      :we can pay for online shopping or restaurant through this online process.For that user has to transfer the amount of money to the Merchant.For the list of Agents there already exists a file named 𝐌𝐄𝐑𝐂𝐇𝐀𝐍𝐓.𝐭𝐱𝐭 .
									• 𝐆𝐈𝐅𝐓/𝐒𝐀𝐋𝐀𝐌𝐈          : A sweet gesture for our dearest one.We can send money on someone's birthday with a sweet note.We can send Eid Card with Eid salami.Hopefully this feature will make our festivals more enjoyable.
									• 𝐕𝐈𝐄𝐖 𝐌𝐄𝐒𝐒𝐀𝐆𝐄        : Whoever sent eid card or note with money,will be shown here with date & time.
									• 𝐋𝐎𝐆 𝐎𝐔𝐓              :After logging out users can't use the previous features of Log in anymore.Menu with 4 options will be shown.
									
•𝐃𝐄𝐋𝐄𝐓𝐄 𝐀𝐂𝐂𝐎𝐔𝐍𝐓       :we can delete account.after that all the information of user and messages or other txt files related to the user will be removed and the number of user from 𝐔𝐒𝐄𝐑.𝐭𝐱𝐭 file will also be removes.If the user again wants to enjoy the featues of this project will have to sign up again.
•𝐄𝐗𝐈𝐓                   :If users want to exit the project that can be done through the feature.

⦾I used 3 classes for different functions and variables and used the concept of constructor ,encapsulation etc also. The class variables are used for handling the data.Here txt files are used.
Check out the code for more!Happy Coding!
|SIS2007110|
