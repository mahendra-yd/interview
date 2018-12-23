   Link: [1]canonical

                                [2]GeeksforGeeks

   A computer science portal for geeks

                                                               [3]     GeeksQuiz

     * [4]Home
     * [5]Algorithms
     * [6]DS
     * [7]GATE
     * [8]Interview Corner
     * [9]Q&A
     * [10]C
     * [11]C++
     * [12]Java
     * [13]Books
     * [14]Contribute
     * [15]Contests
     * [16]Jobs

     * [17]Array
     * [18]Bit Magic
     * [19]C/C++
     * [20]Articles
     * [21]GFacts
     * [22]Linked List
     * [23]MCQ
     * [24]Misc
     * [25]Output
     * [26]String
     * [27]Tree
     * [28]Graph

Tug of War

   Given a set of n integers, divide the set in two subsets of n/2 sizes each
   such that the difference of the sum of two subsets is as minimum as
   possible. If n is even, then sizes of two subsets must be strictly n/2 and
   if n is odd, then size of one subset must be (n-1)/2 and size of other
   subset must be (n+1)/2.

   For example, let given set be {3, 4, 5, -3, 100, 1, 89, 54, 23, 20}, the
   size of set is 10. Output for this set should be {4, 100, 1, 23, 20} and
   {3, 5, -3, 89, 54}. Both output subsets are of size 5 and sum of elements
   in both subsets is same (148 and 148).
   Let us consider another example where n is odd. Let given set be {23, 45,
   -34, 12, 0, 98, -99, 4, 189, -1, 4}. The output subsets should be {45,
   -34, 12, 98, -1} and {23, 0, -99, 4, 189, 4}. The sums of elements in two
   subsets are 120 and 121 respectively.

   The following solution tries every possible subset of half size. If one
   subset of half size is formed, the remaining elements form the other
   subset. We initialize current set as empty and one by one build it. There
   are two possibilities for every element, either it is part of current set,
   or it is part of the remaining elements (other subset). We consider both
   possibilities for every element. When the size of current set becomes n/2,
   we check whether this solutions is better than the best solution available
   so far. If it is, then we update the best solution.

   Following is C++ implementation for Tug of War problem. It prints the
   required arrays.

 #include <iostream>
 #include <stdlib.h>
 #include <limits.h>
 using namespace std;

 // function that tries every possible solution by calling itself recursively
 void TOWUtil(int* arr, int n, bool* curr_elements, int no_of_selected_elements,
              bool* soln, int* min_diff, int sum, int curr_sum, int curr_position)
 {
     // checks whether the it is going out of bound
     if (curr_position == n)
         return;

     // checks that the numbers of elements left are not less than the
     // number of elements required to form the solution
     if ((n/2 - no_of_selected_elements) > (n - curr_position))
         return;

     // consider the cases when current element is not included in the solution
     TOWUtil(arr, n, curr_elements, no_of_selected_elements,
               soln, min_diff, sum, curr_sum, curr_position+1);

     // add the current element to the solution
     no_of_selected_elements++;
     curr_sum = curr_sum + arr[curr_position];
     curr_elements[curr_position] = true;

     // checks if a solution is formed
     if (no_of_selected_elements == n/2)
     {
         // checks if the solution formed is better than the best solution so far
         if (abs(sum/2 - curr_sum) < *min_diff)
         {
             *min_diff = abs(sum/2 - curr_sum);
             for (int i = 0; i<n; i++)
                 soln[i] = curr_elements[i];
         }
     }
     else
     {
         // consider the cases where current element is included in the solution
         TOWUtil(arr, n, curr_elements, no_of_selected_elements, soln,
                   min_diff, sum, curr_sum, curr_position+1);
     }

     // removes current element before returning to the caller of this function
     curr_elements[curr_position] = false;
 }

 // main function that generate an arr
 void tugOfWar(int *arr, int n)
 {
     // the boolen array that contains the inclusion and exclusion of an element
     // in current set. The number excluded automatically form the other set
     bool* curr_elements = new bool[n];

     // The inclusion/exclusion array for final solution
     bool* soln = new bool[n];

     int min_diff = INT_MAX;

     int sum = 0;
     for (int i=0; i<n; i++)
     {
         sum += arr[i];
         curr_elements[i] =  soln[i] = false;
     }

     // Find the solution using recursive function TOWUtil()
     TOWUtil(arr, n, curr_elements, 0, soln, &min_diff, sum, 0, 0);

     // Print the solution
     cout << "The first subset is: ";
     for (int i=0; i<n; i++)
     {
         if (soln[i] == true)
             cout << arr[i] << " ";
     }
     cout << "\nThe second subset is: ";
     for (int i=0; i<n; i++)
     {
         if (soln[i] == false)
             cout << arr[i] << " ";
     }
 }

 // Driver program to test above functions
 int main()
 {
     int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
     int n = sizeof(arr)/sizeof(arr[0]);
     tugOfWar(arr, n);
     return 0;
 }

   Output:

 The first subset is: 45 -34 12 98 -1
 The second subset is: 23 0 -99 4 189 4

   This article is compiled by [29]Ashish Anand and reviewed by GeeksforGeeks
   team. Please write comments if you find anything incorrect, or you want to
   share more information about the topic discussed above.

             

  Related Topics:

     * [30]Find the largest pair sum in an unsorted array
     * [31]Why Quick Sort preferred for Arrays and Merge Sort for Linked
       Lists?
     * [32]Find Union and Intersection of two unsorted arrays
     * [33]Pythagorean Triplet in an array
     * [34]Maximum profit by buying and selling a share at most twice
     * [35]Design a data structure that supports insert, delete, search and
       getRandom in constant time
     * [36]Print missing elements that lie in range 0 – 99
     * [37]Iterative Merge Sort

   Tags: [38]Backtracking

   [39]IFrame
   [40]Tweet
   Writing code in comment? Please use [41]ideone.com and share the link
   here.

     * mani992

       1 more thing can be done to remove recursion:
       1> suppose there are n elements,then iterate over 0->n
       2>in each iteration ,
       suppose i=1 and N=4
       Now, get the bit at the positions from j=0 to j=3 in i,
       if the bit=1 then include that arr[j] in the set1

       else
       include that in set2
       you can get the bit by using : (i&(1< 0)
       3>calculate the diff at the end of each iteration and compare the
       result. Hope I was clear enough.

     * mani992

       1 more solution could be for +ve numbers only in O(nlogn)
       1> find the total sum of the array elements.
       2>let median=total_sum/2
       3>sort the array in descending order
       4> put the element in the first set if the sum(first set)iterate over
       all numbers once

     * Rajan Chaudhary

       is their any other solution instead of compiling every possible set,
       can we use dynamic programming to optimize it

     * Guest

       Please explain this
       // removes current element before returning to the caller of this
       function
       curr_elements[curr_position] = false;

     * Qiang Zhang

       Can we do something like the followings:
       0. we maintain the sum of current left array and right array, which is
       initialized as 0;
       1. sort the array nlogn;
       2. for each pair of adjacent number, we add the larger one the array
       has smaller sum;
       3. continues this, until we finish.

          * Guest

            consider this array 1000,10,9,8,7,6,5,4,3

     * Sriharsha g.r.v

       how about this…
       1:sort it in o(nlogn) time….
       2:place alternate elements in two different arrays..
       it forms the answer….

          * vamshi

            doesnt work for 1, 2, 10, 11

     * renu

       can someone pls tell me what is the time complexity of the above code.
       in microsoft interview the problem was asked to be solved in o(n) time
       complexity without using sorting .can it be really done?

          * rahul

            Complexity is exponential n it is NP hard.So no polynomial 0(n)
            solution is possible for this.It cant be done in 0(n) with n
            without sorting…U have to check all possible combinations:).

     * Gautam

       //Guys i try using Backtracking……
       #include
       #include
       int size=11;//If you r intrested then change the size
       int arr1[size]={0};
       int Final[size];
       int MinDiff=100;//we just assume the MinDiff it may b more
       void FindSubset(int Input[],int Index,int RequiredSum,int Tmpsum)
       {
       if(Index>=size)
       {
       int x=0;
       x=abs(Tmpsum-RequiredSum);
       if(MinDiff>x)
       {
       int i=0;
       for(;i<size;i++)
       {
       Final[i]=arr1[i];
       }
       MinDiff=x;
       }
       return;
       }
       arr1[Index]=Input[Index];
       FindSubset(Input,Index+1,RequiredSum,Tmpsum+Input[Index]);
       arr1[Index]=0;
       FindSubset(Input,Index+1,RequiredSum,Tmpsum);
       }

       int main()
       {
       int Input[size];
       int i=0,TotalSum=0,RequiredSum=0;

       for(;i<size;i++)
       {
       printf("enter %dth element:n",i);
       scanf("%d",&Input[i]);
       TotalSum+=Input[i];
       }
       RequiredSum=TotalSum/2;

       FindSubset(Input,0,RequiredSum,0);//call for FindSubset function
       for(i=0;i<size;i++)
       {
       if(Final[i]!=0)
       printf("%dt",Final[i]);
       }

     * Vinit Gupta

       Guys we can solve this by generating all permutation of that array and
       the answer will be the permutation which has min difference between
       initial n/2 and last n/2 element.

       code for above implementation as follows:-

       #include
       #include
       #include
       using namespace std;
       int minDiff= 10000;
       int sol[1000];
       void replace_Val(int inp[],int i,int j){
       int temp=inp[i];
       inp[i]=inp[j];
       inp[j]=temp;
       }
       int diff(int a[],int n){
       int left=0;
       int right=0;
       for(int i=0;i<=n;i++){
       if(i<n/2)
       left=left+a[i];
       else
       right=right+a[i];
       }
       return abs(left-right);

       }
       void print_All(int a[],int n){
       for(int i=0;i<=n;i++)
       cout<<a[i]<<" ";
       cout<<endl;
       }
       void copy_Array(int a[],int b[],int n){
       for(int i=0;i<=n;i++){
       b[i]=a[i];
       }
       }
       void solve_TugWar(int input[],int index,int n){
       if(index<n){
       for(int i=index;itemp){
       minDiff=temp;
       copy_Array(input,sol,n);
       }
       }
       }

       int main(){
       int arr[] = {23,45,-34,12,0,98,-99,4,189,-1,4};
       int n = sizeof(arr)/sizeof(arr[0]);
       solve_TugWar(arr,0,n-1);
       cout<<"solution is "<< minDiff<<endl;
       print_All(sol,(n-1)/2-1);
       }

     * rakitic

       @geeks…what is the purpose for making the current_position false in
       last statement ??
       }
       else
       {
       // consider the cases where current element is included in the
       solution
       TOWUtil(arr, n, curr_elements, no_of_selected_elements, soln,
       min_diff, sum, curr_sum, curr_position+1);
       }

       // removes current element before returning to the caller of this
       function
       curr_elements[curr_position] = false;
       }

          * Debjyoti Roy

            I think it’s the backtracking step…

     * Parin

       Is this code correct?
       Also,if you can answer if this is efficient enough?


 /* Paste your code here (You may delete these lines if not writing code) */

 class demo
 {
     public static void main(String args[]) throws Exception
     {
         Thread d=new Thread();
         int ss=0,mm=0,hr=0;
         while(true)
         {
                 d.sleep(1000);
                 ss++;
                 if(ss==60)
                 {
                         mm++;
                         ss=0;
                 }
                 if(mm==60)
                 {
                         hr++;
                         mm=0;
                 }
                 System.out.println(hr+":"+mm+":"+ss);
                 if(hr==24)
                         System.exit(0);
         }
     }
 }


     * Parin

       IS this code correct?
       And also if you can answer,please tell me if this is efficient or not.
       import java.util.*;
       class demo
       {
       static int n=0,count=0,taken=0,remain=0,min=20000,test=0;
       static int x[],y[],a[];
       public static void main(String args[])
       {
       System.out.print(“Enter array size.”);
       Scanner sc=new Scanner(System.in);
       n=sc.nextInt();
       x=new int[n];
       y=new int[n];
       a=new int[n];
       System.out.println(“Enter elements”);
       for(int i=0;i<n;i++)
       {
       x[i]=sc.nextInt();
       }
       System.out.println("Hello");
       TugOfWar(0);

       for(int i=0;i<n;i++)
       {
       if(a[i]==1)
       System.out.println(x[i]);
       }
       System.out.println("Minimum difference is"+min);

       }
       static void TugOfWar(int k)
       {

       if(k==n)
       {
       for(int i=0;i<n;i++)
       {
       if(y[i]==1)
       count++;

       }

       if(count==(n/2+n%2))
       {

       for(int i=0;i0)
       test=taken-remain;
       else
       test=remain-taken;

       if(test<min)
       {
       min=test;
       for(int i=0;i-1;i–)
       {
       y[k]=i;
       TugOfWar(k+1);
       }
       }
       }
       }

     * bateesh

       Can anyone explain how to apply partioning approach in this?I tried
       but unable to do so as we need to maintain n/2 elements also.We can
       also do it by creating a 2-d matrix and of n*n.where matrix[i][j] will
       represent sum of elements from i to j and apply same approach as of
       recurssion but it will not have overlapping subproblems as we have
       already obtained sum from i to j.Say i have 6 elements then to select
       3 from them(1,2,3,4,5,6) i will start from reverse order.Say,i start
       from 4,5,6 first.Then move one backward to 3 then from 3 we fix 3 and
       find sum 4-5 (3+4+5),then 4 and 6(3+4+6),then 5-6(3+5+6).And find
       minimum and update minimum solution set if possible.Then move to 2 and
       find all set from 2 to n of size 3 which will have one element as
       2.Plz comment on this approach.
       0(n^2) is not possible for this i think.

          * Gautam

            plz copy my code and run it using gcc and go step by step i think
            u will find all the thing clearly

     * http://mytechdiet.com Rahul

       I guess there will be two solutions for this example.
       One that is stated above and other can be:
       First set:45 -34 12 98 0
       Second set:23 -1 -99 4 189 4

     * AMIT

       I think better algorithms exists for such problems of divisions into
       half equal partitions–KL algorithm(algorithm for partitioning) was one
       such algorithm with a non-exponential time complexity.Please correct
       me if I am wrong

     * Vishnu Vasanth R

       Hi All, The solution for Tug of war looks like Backtracking | Set 4
       (Subset Sum)problem. I have reused its function to simplify the
       answer. It gives correct solution. Someone please update the answer
       with my code. This is way too easy.

       /* Paste your code here (You may delete these lines if not writing
       code) */
       // TugOfWar.cpp : Defines the entry point for the console application.
       //

       #include “stdafx.h”

       #include
       #include
       #include using namespace std;
       static int total_nodes;

       // function that tries every possible solution by calling itself
       recursively
       void TOWUtil(int* arr, int n, bool* curr_elements, int
       no_of_selected_elements,
       bool* soln, int* min_diff, int sum, int curr_sum, int curr_position)
       {
       total_nodes++;

       // checks if a solution is formed
       if (no_of_selected_elements == n/2)
       {
       // checks if the solution formed is better than the best solution so
       far
       if (abs(sum/2 – curr_sum) < *min_diff)
       {
       *min_diff = abs(sum/2 – curr_sum);
       for (int i = 0; i<n; i++)
       soln[i] = curr_elements[i];
       }

       return;
       }

       else{

       if (curr_position != n && (n/2 – no_of_selected_elements) < (n –
       curr_position)){

       for(int i = curr_position; i<n;i++){

       curr_elements[i] = true;

       TOWUtil(arr, n, curr_elements, no_of_selected_elements+1, soln,
       min_diff, sum, curr_sum + arr[i], i+1);

       curr_elements[i] = false; // backtrack
       }

       }

       }

       }

       // main function that generate an arr
       void tugOfWar(int *arr, int n)
       {
       // the boolen array that contains the inclusion and exclusion of an
       element
       // in current set. The number excluded automatically form the other
       set
       bool* curr_elements = new bool[n];

       // The inclusion/exclusion array for final solution
       bool* soln = new bool[n];

       int min_diff = INT_MAX;

       int sum = 0;
       for (int i=0; i<n; i++)
       {
       sum += arr[i];
       curr_elements[i] = soln[i] = false;
       }

       // Find the solution using recursive function TOWUtil()
       TOWUtil(arr, n, curr_elements, 0, soln, &min_diff, sum, 0, 0);

       // Print the solution
       cout << “The first subset is: “;
       for (int i=0; i<n; i++)
       {
       if (soln[i] == true)
       cout << arr[i] << ” “;
       }
       cout << “\nThe second subset is: “;
       for (int i=0; i<n; i++)
       {
       if (soln[i] == false)
       cout << arr[i] << ” “;
       }
       }

       // Driver program to test above functions
       int main()
       {
       int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
       int n = sizeof(arr)/sizeof(arr[0]);
       tugOfWar(arr, n);
       printf(“Nodes generated %d\n”, total_nodes);
       return 0;
       }

     * http://www.cse.iitb.ac.in/~saha/ subhasish

       Please check the following algo and point out if something is wrong :

       1. sort the array
       2. Initialize two sets with two largest numbers
       3. Loop until #remaining element <= 1
       —a. If sum of set 1 is greater than sum of set 2 include smallest
       among remaining elements, else include greatest element
       —b. Similarly add one element to set 2
       4. If any item remains (odd number of elements) add to the set having
       smaller sum

       /* Paste your code here (You may delete these lines if not writing
       code) */

          * Rohit

            I guess it fails in following case:
            3,4,5,6,9,11,100,110
            set 1 = 110, 3, 4, 6 = 123
            set 2 = 100, 11, 9, 5 = 125

            but answer should be set 1 = 110, 3, 5, 6 = 124
            and set 2 = 100, 11, 9, 4 = 124

     * Prateek Sharma

       Python code with o(n^2)complexity……

       import math
       import copy
       import sys
       storingArray =[]
       def binaryConversion(length):
       if length < 0:
       return 0
       else:
       remainder =[]
       n = length
       while n != 0:
       remainder.append(n%2)
       n = n/2
       length -=1
       storingArray.append(remainder)
       binaryConversion(length)
       return 0

       def tugOfWar(a):
       newArray =[]
       sumArray =[]
       length = len(a)
       length = int(math.pow(2,length))-1
       binaryConversion(length)
       for i in range(len(storingArray)):
       tempArray =[]
       for j in range(len(storingArray[i])):
       if storingArray[i][j] ==1:
       tempArray.append(a[j])
       newArray.append(tempArray)
       length = len(a)
       if length%2 == 0:
       for i in range(len(newArray)):
       if len(newArray[i]) != length/2:
       newArray[i] = [None]
       newArray[:] = [x for x in newArray if x != [None]]
       else:
       for i in range(len(newArray)):
       if len(newArray[i]) != (length-1)/2 and len(newArray[i]) !=
       (length+1)/2:
       newArray[i] = [None]
       newArray[:] = [x for x in newArray if x != [None]]
       for i in range(len(newArray)):
       sum = 0
       for j in range(len(newArray[i])):
       sum = sum + newArray[i][j]
       sumArray.append(sum)
       diff = sys.maxint
       print newArray
       for i in range(len(newArray)):
       for j in range(len(newArray)):
       if i != j:
       if (sumArray[i] – sumArray[j])>=0 and (sumArray[i] – sumArray[j]) <
       diff:
       diff = sumArray[i] – sumArray[j]
       first = newArray[i]
       second = newArray[j]
       print "Two subsets are" +str(first) + "and"+ str(second)

       def main():
       array =[1,2,3]
       tugOfWar(array)
       if __name__ == ‘__main__':
       main()

     * http://www.piyush.co.nf binary001

       @dada786

       1) Sort the elements
       2) select alternate numbers for one set and remaining are in the other
       set ..

       if some test case not working please let me know

          * DashDash

            Not necessarily
            Take 10 80 100

            Alternate means 10 + 100 and 80 while solution is 10+80 and 100

               * binary001

                 got that …. thanks..

                    * din

                      sort the array ,if n is even select alternate numbers
                      for one set and remaining are in the other set
                      if n is odd,do the above until one element is left,add
                      that in the set with less sum…
                      pls validate me…..

                         * din

                           sorry
                           it doesn’t work………..

     * abhishek08aug

       Intelligent 😀


 /* Paste your code here (You may delete these lines if not writing code) */


          * rakitic

            you should try solving yourself first before looking for
            solution….may be you will not find it too much intelligent then
            [42]:)

     * Niks


 #include <iostream>
 #include <stdlib.h>
 #include <limits.h>
 using namespace std;

 int res = INT_MAX;

 // function that tries every possible solution by calling itself recursively
 void TOWUtil(int* arr, int n, int sum, int curr_sum, int curr_position,int count)
 {
     // checks whether the it is going out of bound
     if (count == (n/2))
         {
                 int x = sum - curr_sum;
                 res = min(res,abs(x-curr_sum));
                 return;
         }

         if(curr_position == n)
                 return;
     // consider the cases when current element is not included in the solution
     TOWUtil(arr, n, sum, curr_sum, curr_position+1,count);

     // consider the cases where current element is included in the solution
         TOWUtil(arr, n, sum, curr_sum+arr[curr_position], curr_position+1,count+1);
 }

 // main function that generate an arr
 void tugOfWar(int *arr, int n)
 {
     // the boolen array that contains the inclusion and exclusion of an element
     // in current set. The number excluded automatically form the other set
     bool* curr_elements = new bool[n];

     // The inclusion/exclusion array for final solution
     bool* soln = new bool[n];

     int min_diff = INT_MAX;

     int sum = 0;
     for (int i=0; i<n; i++)
     {
         sum += arr[i];
         curr_elements[i] =  soln[i] = false;
     }

     // Find the solution using recursive function TOWUtil()
     TOWUtil(arr, n, sum, 0, 0, 0);

         cout << res << " ";

 }

 // Driver program to test above functions
 int main()
 {
         res = INT_MAX;
         int arr[] = {3, 4, 5, -3, 100, 1, 89, 54, 23, 20};
     int n = sizeof(arr)/sizeof(arr[0]);
     tugOfWar(arr, n);
     return 0;
 }


     * Sagar

       Find the largest element and put it in set 1.
       Find the next largest and put it in set 2.
       Then compare the sum of values in set 1 and set 2.
       If set 2<set 1, insert the third largest in set 2 and fourth largest
       in set 1. Else do the opposite.
       Repeat till you run out of elements.

          * Gaurav

            Suppose we have an array: 3,5,7,8,9,10,15,64,89,100.
            Then according to your solution, we would end up getting 7
            elements in one subset and 3 in another. Can you please explain
            how it would work for the above mentioned case.


 /* Paste your code here (You may delete these lines if not writing code) */


               * prity

                 Can u plz tell that what is the output of an array given by
                 you: 3,5,7,8,9,10,15,64,89,100.
                 According to me sagar’s approach would work fine in all
                 case.

                    * Rohit

                      Take the case 3,5,9,100,110
                      set 1 = 110
                      set 2 = 100
                      set 2 < set 1 so 9 is added to set 2
                      and following that we have final sets as set 1 = 110, 5
                      set2 = 100, 9, 3
                      sum(set 1) = 115
                      sum(set 2) = 112
                      but answer should be 113(110+3) and 114(100+9+5). And
                      so it fails.

                      /* Paste your code here (You may delete these lines if
                      not writing code) */

                         * DMK

                           Please check it once again, you will get the
                           correct answer for your input following this
                           approach.

                         * Rohit

                           @DMK: Please explain the approach on given example
                           or show me where I am making mistake.


 /* Paste your code here (You may delete these lines if not writing code) */


                    * rakitic

                      for above case = {3,4,5,-3,100,1,89,54,23,20}

                      yourmethodwillgive{100,23,20,4,3,-3} = 147
                      {89,54,5,1} = 149
                      while correct output is 148 + 148

     * atul

       in given code , why curr_position which is an array index is taking
       part of a base cases.


 if ((n/2 - no_of_selected_elements) > (n - curr_position))
         return;


       cant we make base condition as follows:-


 if(no_of_selected_elements > n/2)
     return;


     * Niks

       Can someone explain the reason for this statement??
       // removes current element before returning to the caller of this
       function
       curr_elements[curr_position] = false;

          * Arvind B R

            once the function is returned ,the sub problem is different ..you
            may not be using that element in other sub problems, so remove
            it.
            eg:
            assume the function call tree is like
            3
            / \
            1 2 in the sub problem that includes 3 and
            / \ 2 only ,u should nt include 1 ,4 or 5
            4 5 wherelse in the sub problem 3,1,5 u shouldnt be using 4 ,so u
            remove 4 from current elements before returning the function.

     * Niks

       We can modify this to print subsets also.It will timeout for large
       values.


 // main function that generate an arr
 int tugOfWar(int *arr, int n)
 {
         int len = 1<<n;
         bool visited[20];
         int res = INT_MAX;

         for(int i=0; i<len; i++)
         {
                 memset(visited,false,sizeof(visited));
                 int cnt = 0;
                 for(int j=0; j<n; j++)
                 {
                         if(i & (1 << j))
                         {
                                 visited[j] = true;
                                 cnt++;
                         }
                 }

                 if(cnt == ((n-1)/2))
                 {
                         int sum1 = 0;
                         int sum2 = 0;
                         for(int i=0; i<n; i++)
                         {
                                 if(visited[i] == false)
                                         sum1+=arr[i];
                                 else if(visited[i])
                                         sum2+=arr[i];
                         }

                         res = min(res, abs(sum1-sum2));
                 }
         }

         return res;
 }



     * Anushka Garg

       You may find more info on this link

       [43]http://www.learnalgorithms.in

     * http://shoutz.in kevindra

       Time complexity of your code is exponential. We can easily use the DP
       to reduce the time to O(n^2K) (worst case) where n is the number of
       elements and each element value rages from 0 to K

       We declare a two dimensional matrix:

       DP[i][j] = 1 if some subset of A[0..i] has a sum of j
       = 0 otherwise

       Recursive formula would be
       DP[i][j] = max( DP[i-1][j], DP[i-1][j-A[i]] )

       We can also use OR operate in place of max. Here is the code.


 int dp[20][1000];  // just for the simplicity
 void balancedPartition(int a[], int n)
 {
     int sum = 0;
     FI(i,0,n) sum+=a[i];

     dp[0][0] = 1;
     FI(i,1,n) FI(j,0,sum+1)
         if(j < a[i]) dp[i][j] = dp[i-1][j];
         else dp[i][j] = dp[i-1][j] | dp[i-1][j-a[i]];

     int firstPartition = 0, secondPartition = 0;
     int mindiff = 1<<30;
     FI(i,0,sum+1)
         if(dp[n-1][i])
             if(abs(2*i - sum) < mindiff){
                 mindiff = abs(2*i-sum);
                 firstPartition = i;
             }
     secondPartition = sum - firstPartition;
     cout<<"First partition: "<<firstPartition<<endl;
     cout<<"Second partition: "<<secondPartition<<endl;
 }


          * olek

            Doesn’t work with negatives

               * olek

                 moreover, for (1,1,1,5) your algorithm will return 3 and 5
                 istead of 2 and 6

     * http://dadakhalandhar.wordpress.com/ dada786

       I think this will work.
       1) Sort the elements
       2) Find middle element, take up-to middle element as one set and
       remaining elements as other. This will give the minimum difference
       required. In case off odd number of elements take one of the middle
       element that gives minimum difference.

       This will take O(n log n).

       Did I go somewhere wrong, if so please correct me.


 /* Paste your code here (You may delete these lines if not writing code) */


          * ibnipun10

            What do you mean by take up to middle element

               * http://dadakhalandhar.wordpress.com/ dada786

                 A small correction,
                 After sorting we partition the array in the middle,
                 and take partition of each of them in the middle. Then the
                 array becomes 4 partitions.
                 Take 1 and 4 into one set and 2 and 3 into other set.
                 For example, if we are given 1,3,8,6,4,2,5,7 we sort them
                 then 1,2,3 …., 8. Partition will partitions will be
                 {1,2},{3,4},{5,6},{7,8} and the two sets will be
                 {1,2,7,8} and {3,4,5,6}.

          * http://shoutz.in kevindra

            No this will not work!

               * http://dadakhalandhar.wordpress.com/ dada786

                 why it will not work, can you please explain with an
                 example?

                    * http://shoutz.in kevindra

                      Try this, lets say you get this array after sorting the
                      numbers:
                      {2,2,3,3,5,5,7,8}
                      Your partitions would be
                      {2,2},{3,3},{5,5},{7,8}
                      then {2,2,7,8}, {3,3,5,5}
                      = sum of left partition = 19
                      = sum of right partition = 16

                      However, if we divide in the following partitions:
                      {3,3,5,7}, {2,2,5,8}
                      = [18] [17]

                      This problem can not be solved greedily, because every
                      decision depends on the decision you made in past. So
                      we have to use dynamic programming. See my solution.

                         * http://dadakhalandhar.wordpress.com/ dada786

                           In case of repetitions we won’t consider the
                           repeated pairs while partitioning.
                           In the above example 2,3,4 are repeated, so while
                           partitioning we won’t consider them (we won’t
                           consider only in pairs). So we remain with only 7
                           and 8. These will go into different partitions.
                           Then each unconsidered pair, is distributed
                           between them. In the above example The over all
                           partition will be {2,3,5,7} {2,3,5,8}

     * Vigadan

       Can you bit explain your logic in detail?

     * http://gravatar.com/techmadememad techmadememad

       what is the time complexity and space complexity of this algorithm ?

          * kartik

            Time complexity seems to be O(n * 2^(n/2))

               * http://gravatar.com/techmadememad techmadememad

                 O(n * 2^(n/2)) not polynomial complexity have you tries for
                 some 1000 numbers. seems like a np-completeness problem


 /* Paste your code here (You may delete these lines if not writing code) */


                    * raja

                      Your argument doesn’t make sense as yhe time complexity
                      provided by Kartik is exponential.

     * 

     * 




     * 

     * 
          * [44]Interview Experiences
          * [45]Advanced Data Structures
          * [46]Dynamic Programming
          * [47]Greedy Algorithms
          * [48]Backtracking
          * [49]Pattern Searching
          * [50]Divide & Conquer
          * [51]Mathematical Algorithms
          * [52]Recursion
          * [53]Geometric Algorithms

     * 

     * Popular Posts

          * [54]All permutations of a given string
          * [55]Memory Layout of C Programs
          * [56]Understanding “extern” keyword in C
          * [57]Median of two sorted arrays
          * [58]Tree traversal without recursion and without stack!
          * [59]Structure Member Alignment, Padding and Data Packing
          * [60]Intersection point of two Linked Lists
          * [61]Lowest Common Ancestor in a BST.
          * [62]Check if a binary tree is BST or not
          * [63]Sorted Linked List to Balanced BST

     * [64]Follow @GeeksforGeeks
     * Recent Comments

     * 



   @geeksforgeeks, [65]Some rights reserved [66]       Contact Us! [67]     
    Abut Us!
   Powered by [68]WordPress & [69]MooTools, customized by geeksforgeeks

References

   Visible links
   1. http://www.geeksforgeeks.org/tug-of-war/
   2. GeeksforGeeks
	http://www.geeksforgeeks.org/
   3. http://geeksquiz.com/
   4. http://www.geeksforgeeks.org/
   5. http://www.geeksforgeeks.org/fundamentals-of-algorithms/
   6. http://www.geeksforgeeks.org/data-structures/
   7. http://www.geeksforgeeks.org/gate-corner/
   8. http://www.geeksforgeeks.org/about/interview-corner/
   9. http://www.geeksforgeeks.org/forums/
  10. http://www.geeksforgeeks.org/c/
  11. http://www.geeksforgeeks.org/c-plus-plus/
  12. http://www.geeksforgeeks.org/java/
  13. http://www.geeksforgeeks.org/books/
  14. http://www.geeksforgeeks.org/contribute/
  15. http://www.geeksforgeeks.org/contests/
  16. http://www.geeksforgeeks.org/jobs/
  17. Questions regarding Arrays
	http://www.geeksforgeeks.org/category/c-arrays/
  18. View all posts filed under Bit Magic
	http://www.geeksforgeeks.org/category/bit-magic/
  19. View all posts filed under C/C++ Puzzles
	http://www.geeksforgeeks.org/category/c-puzzles/
  20. View all posts filed under Articles
	http://www.geeksforgeeks.org/category/articles/
  21. View all posts filed under GFacts
	http://www.geeksforgeeks.org/category/gfact/
  22. Linked List problems
	http://www.geeksforgeeks.org/category/linked-list/
  23. View all posts filed under MCQ
	http://www.geeksforgeeks.org/category/multiple-choice-question/
  24. Miscellaneous
	http://www.geeksforgeeks.org/category/c-programs/
  25. View all posts filed under Output
	http://www.geeksforgeeks.org/category/program-output/
  26. Questions related to strings
	http://www.geeksforgeeks.org/category/c-strings/
  27. View all posts filed under Trees
	http://www.geeksforgeeks.org/category/tree/
  28. View all posts filed under Graph
	http://www.geeksforgeeks.org/category/graph/
  29. https://www.facebook.com/aasshishh?fref=ts
  30. Find the largest pair sum in an unsorted array
	http://www.geeksforgeeks.org/find-the-largest-pair-sum-in-an-unsorted-array/
  31. Why Quick Sort preferred for Arrays and Merge Sort for Linked Lists?
	http://www.geeksforgeeks.org/why-quick-sort-preferred-for-arrays-and-merge-sort-for-linked-lists/
  32. Find Union and Intersection of two unsorted arrays
	http://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/
  33. Pythagorean Triplet in an array
	http://www.geeksforgeeks.org/find-pythagorean-triplet-in-an-unsorted-array/
  34. Maximum profit by buying and selling a share at most twice
	http://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/
  35. Design a data structure that supports insert, delete, search and getRandom in constant time
	http://www.geeksforgeeks.org/design-a-data-structure-that-supports-insert-delete-search-and-getrandom-in-constant-time/
  36. Print missing elements that lie in range 0 – 99
	http://www.geeksforgeeks.org/print-missing-elements-that-lie-in-range-0-99/
  37. Iterative Merge Sort
	http://www.geeksforgeeks.org/iterative-merge-sort/
  38. http://www.geeksforgeeks.org/tag/backtracking/
  39. http://www.facebook.com/plugins/like.php?href=http%3A%2F%2Fwww.geeksforgeeks.org%2Ftug-of-war%2F&layout=button_count&show_faces=false&width=90&action=like&colorscheme=light
  40. http://twitter.com/share
  41. http://ideone.com/
  43. http://www.learnalgorithms.in/
  44. http://www.geeksforgeeks.org/category/interview-experiences/
  45. http://www.geeksforgeeks.org/tag/advance-data-structures
  46. http://www.geeksforgeeks.org/tag/dynamic-programming
  47. http://www.geeksforgeeks.org/tag/Greedy-Algorithm/
  48. http://www.geeksforgeeks.org/tag/backtracking
  49. http://www.geeksforgeeks.org/tag/pattern-searching
  50. http://www.geeksforgeeks.org/tag/divide-and-conquer
  51. http://www.geeksforgeeks.org/tag/MathematicalAlgo
  52. http://www.geeksforgeeks.org/tag/recursion
  53. http://www.geeksforgeeks.org/tag/geometric-algorithms/
  54. http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
  55. http://www.geeksforgeeks.org/memory-layout-of-c-program/
  56. http://www.geeksforgeeks.org/understanding-extern-keyword-in-c/
  57. http://www.geeksforgeeks.org/median-of-two-sorted-arrays/
  58. http://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
  59. http://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/
  60. http://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
  61. http://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/
  62. http://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
  63. http://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/
  64. https://twitter.com/GeeksforGeeks
  65. Valid XHTML Strict 1.0
	http://creativecommons.org/licenses/by-nc-nd/2.5/in/deed.en_US
  66. http://www.geeksforgeeks.org/about/contact-us/
  67. http://www.geeksforgeeks.org/about/
  68. http://wordpress.org/
  69. Mootools JavaScript Framework
	http://mootools.net/
