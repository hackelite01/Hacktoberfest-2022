#include<iostream>
using namespace std;
int main()
{
int w,i,f,frames[50];
cout<<"Enter window size: ";
cin>>w;
cout<<"\nEnter number of frames to transmit: ";
cin>>f;
cout<<"\nEnter "<<f<<" frames: ";
for(i=1;i<=f;i++)
cin>>frames[i];
cout << "\nWith sliding window protocol the frames will be sent in the following manner (assuming no corruption of frames)\n\n ";
cout << "After sending " << w << " frames at each stage sender waits for acknowledgement sent by the receiver\n\n ";

for(i=1;i<=f;i++)
{
if(i%w==0)
{
cout<<frames[i]<<"\n";
cout<<"Acknowledgement of above frames sent is received by sender\n\n";
}
else
cout<<frames[i]<<" ";
}
if(f%w!=0)
cout<<"\nAcknowledgement of above frames sent is received by sender\n";
return 0;
}