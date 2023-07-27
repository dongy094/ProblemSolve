import java.util.Scanner;
import java.util.*;

public class Main {

    static int N;
    static int M;
    static int[][] map;
    static boolean[] visit;
    static int result = 0;

    static void solve(int start){
        Queue<Integer> queue = new LinkedList<>();
        visit[start] = true;
        queue.offer(start);

        while(!queue.isEmpty()){
            int pos = queue.poll();
            for(int i=1;i<=N;++i){
                if(!visit[i] && map[pos][i] == 1){
                    queue.offer(i);
                    visit[i] = true;
                    result++;
                }
            }
        }


    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();

        visit = new boolean[N+1];
        map = new int[N+1][N+1];
        for(int i=0;i<M;++i){
            int from = sc.nextInt();
            int to = sc.nextInt();
            map[from][to] = map[to][from] = 1;
        }


        solve(1);

        System.out.print(result);

    }

}
