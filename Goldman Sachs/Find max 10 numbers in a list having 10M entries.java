

import java.util.PriorityQueue;
import java.util.Scanner;

public class {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        PriorityQueue<Integer> pq=new PriorityQueue<>();
        for(int i=0;i<10;i++)
        {
            pq.add(sc.nextInt());
        }
        for(int i=10;i<(long long)1e7;i++)
        {
            int x=sc.nextInt();
            if(x>pq.peek())
            {
                pq.poll();
                pq.add(x);
            }
        }

        System.out.println("All the entries are:");
        while(!pq.isEmpty())
        {
            System.out.print(pq.poll());
        }
    }
}
