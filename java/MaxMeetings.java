import java.util.*;

//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

public class MaxMeetings {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Size of Array");
        int size = sc.nextInt();

        int[] start = new int[size];
        for(int i=0; i<size; i++){
            start[i] = sc.nextInt();
        }

        int[] end = new int[size];
        for(int i=0; i<size; i++){
            end[i] = sc.nextInt();
        }

        System.out.println(maxMeetings(start, end));
    }

    private static int maxMeetings(int[] start, int[] end) {
        int total = 0, mend=0;

        List<Meeting> meetings = new ArrayList<>();
        for(int i=0; i<start.length; i++)
            meetings.add(new Meeting(start[i], end[i], i));

        Collections.sort(meetings);

        for(Meeting meeting : meetings){
            if(meeting.start>mend){
                mend = meeting.end;
                total++;
            }
        }

        return total;
    }

    private static class Meeting implements Comparable<Meeting> {

        int start;
        int end;
        int index;

        public Meeting(int start, int end, int index) {
            this.start = start;
            this.end = end;
            this.index = index;
        }

        @Override
        public int compareTo(Meeting o) {

            if(this.end > o.end)
                return 1;
            else if (this.end == o.end) {
                return 0;
            }
            return -1;
        }

        @Override
        public String toString() {
            return "Meeting{" +
                    "start=" + start +
                    ", end=" + end +
                    ", index=" + index +
                    '}';
        }
    }
}
