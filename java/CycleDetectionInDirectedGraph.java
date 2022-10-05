import java.util.ArrayList;
import java.util.Scanner;

https://www.interviewbit.com/problems/cycle-in-directed-graph/

public class CycleDetectionInDirectedGraph {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int v = sc.nextInt();
        int e = sc.nextInt();
        int[][] edges = new int[e][2];
        for(int i=0; i<e; i++){
            edges[i][0] = sc.nextInt();
            edges[i][1] = sc.nextInt();
        }

        System.out.println(detectBFScycle(v, edges));
    }

    private static boolean detectBFScycle(int v, int[][] edges) {
        ArrayList<Integer>[] adja = new ArrayList[v];
        for(int i=0; i<adja.length; i++){
            adja[i] = new ArrayList<>();
        }

        for(int[] edge : edges){
            adja[edge[0]].add(edge[1]);
            // adja[edge[1]].add(edge[0]);
        }

        int[] visited = new int[v];

        for(int i=0; i<v; i++){
            if(!check(i, visited, adja)){
                return false;
            }
        }

        return true;
    }

    private static boolean check(int i, int[] visited, ArrayList<Integer>[] adja){

        if(visited[i] == 1) return false;

        visited[i] = 1;
        for(int node : adja[i]){
            if(visited[node] != 2){
                if(!check(node, visited, adja)){
                    return false;
                }
            }
        }
        visited[i] = 2;

        return true;
    }
}
