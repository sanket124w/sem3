'''
Write a Python program to store first year percentage of
students in array. Write function for sorting array of floating point
numbers in ascending order using
a) Selection Sort
b) Bubble sort and display top five scores.
'''

#Input of Marks
marks=[]
n=int(input("Enter the no. of students :"))
for k in range(0,n):
    ele=float(input("Enter the percentage :"))
    marks.append(ele)

print("List of Percentage Before Sorting",marks)

def SelectionSort(marks,n):
    #Selection Sort
    min_pos=0
    for i in range(0,n-1):
        min_pos=i
        for j in range(i+1,n):
            if marks[j]<marks[min_pos]:
                min_pos=j
                temp1=marks[i]
                marks[i]=marks[min_pos]
                marks[min_pos]=temp1
    
def BubbleSort(marks,n):
    #Bubble Sort
    for i in range(0,n):
        for j in range(0,n-i-1):
            if(marks[j]>marks[j+1]):
                temp=marks[j]
                marks[j]=marks[j+1]
                marks[j+1]=temp

#Sorting ALgorithms
print("\n\t * * * MENU * * *")
print("1. Selection Sort\n2. Bubble Sort")
ch=int(input("Enter your choice :"))
if(ch==1):
    print("Sorting using Selection Sort :")
    SelectionSort(marks, n)
    print(marks)
elif(ch==2):
    print("Sorting using Bubble Sort :")
    BubbleSort(marks,n)
    print(marks)
else:
    print("Wrong Input !!")

#Output
'''
Enter the no. of students :6
Enter the percentage :12
Enter the percentage :17
Enter the percentage :15
Enter the percentage :10
Enter the percentage :19
Enter the percentage :11
List of Percentage Before Sorting [12.0, 17.0, 15.0, 10.0, 19.0, 11.0]

         * * * MENU * * *
1. Selection Sort
2. Bubble Sort
Enter your choice :1
Sorting using Selection Sort :
[11.0, 10.0, 12.0, 15.0, 17.0, 19.0]
'''
