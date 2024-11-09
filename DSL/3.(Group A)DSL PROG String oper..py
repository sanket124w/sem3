'''Write a Python program to compute following operations on String:
a) To display word with the longest length
b) To determines the frequency of occurrence of particular character in the string
c) To check whether given string is palindrome or not
d) To display index of first appearance of the substring
e) To count the occurrences of each word in a given string'''

dict_freq={}
dict_len={}

#Function Definitions
def word_length(string):
	#Display word with longest length
	indiv=string.split()
	len_list=len(indiv)
	for word in range(0,len_list):
		dict_len[indiv[word]]=len(indiv[word])
	#print(dict_len)
	high=max(dict_len.values())
	long_word= [k for k, v in dict_len.items() if v == high]
	#long_word=max(indiv,key=len)
	return long_word
		
def occur_char(string):
	#calculate frequency of a particular character
	count_occur=0
	word=input("\nEnter the character whose occurance has to be found :")
	for char in range(0,length):
		if string[char]==word:
			count_occur+=1
	return count_occur
		
def palindrome(string):
	#check if the string is palindrome or not 
	str2=string[::-1]
	if (string==str2):
		print("\nThe Given String is a Palindrome")
	else:
		print("\nThe Given String is not a Palindrome")

def index_substring(string):
	#Return the index of first apperance of the substring
	sub_str=input("\nEnter the Substring whose position has to be found : ")
	index_pos=string.find(sub_str)
	return index_pos

def occur_word(string):
	#Count occurances of each word
	print("\nCounting Occurances of Each Word-") 
	indiv=string.split()
	len_list=len(indiv)
	count=0
	for k in range(0,len_list):
		for m in range(0,len_list):
			if indiv[k]==indiv[m]:
				count+=1
		#print("Element - ",indiv[k]," - occurs",count,"times")
		
		dict_freq[indiv[k]]=count
		count=0
	print("Dictionary is of form - Word::Occurance")
	print(dict_freq)

#String Input 
str1=input("\nEnter the String : ")
length=len(str1)

choice='y'
while (choice=='y'):

	#Print Menu
	print("----------------------------------------------------------------------------------------------------------------")
	print("\n\t\t* * * MENU * * *")
	print("Enter 1 To display word with the longest length\nEnter 2 to determine the frequency of occurrence of particular character in the string\nEnter 3 to check whether given string is palindrome or not \nEnter 4 to display index of first appearance of the substring\nEnter 5 to count the occurrences of each word in a given string")

	#Choice from User
	ch=int(input("Enter your Choice :"))

	#Menu-Based
	if ch==1:
		#Word with longest length
		print("\nThe Word with the longest length is :",word_length(str1))
	elif ch==2:
		#Frequency of particular character
		print("Frequency of the entered character is :",occur_char(str1))	
	elif ch==3:
		#Check Palindrome
		palindrome(str1)	
	elif ch==4:
		#Index of Substring
		print("Index position of the 1st apperance of Substring is :",index_substring(str1))
	elif ch==5:
		#Each Word Occurance
		occur_word(str1)	
	else:
		print("Wrong Input !!")		
	print("------------------------------------------------------------------------------------------------------------------")
	choice=input("Do you want to continue (y/n):")																						

#Output
'''
Enter the String : madam
----------------------------------------------------------------------------------------------------------------

                * * * MENU * * *
Enter 1 To display word with the longest length
Enter 2 to determine the frequency of occurrence of particular character in the string
Enter 3 to check whether given string is palindrome or not
Enter 4 to display index of first appearance of the substring
Enter 5 to count the occurrences of each word in a given string
Enter your Choice :2

Enter the character whose occurance has to be found :m
Frequency of the entered character is : 2
------------------------------------------------------------------------------------------------------------------
Do you want to continue (y/n):y
----------------------------------------------------------------------------------------------------------------

                * * * MENU * * *
Enter 1 To display word with the longest length
Enter 2 to determine the frequency of occurrence of particular character in the string
Enter 3 to check whether given string is palindrome or not
Enter 4 to display index of first appearance of the substring
Enter 5 to count the occurrences of each word in a given string
Enter your Choice :3

The Given String is a Palindrome
------------------------------------------------------------------------------------------------------------------
Do you want to continue (y/n):n
'''
