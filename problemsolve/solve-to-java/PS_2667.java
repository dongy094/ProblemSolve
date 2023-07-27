import java.util.Scanner;
import java.util.*;

public class Main {

    static int N;
    static int[][] map;
    static boolean[][] visited;
    static int[] dx = {0,0,-1,1};
    static int[] dy = {1,-1,0,0};
    static int[] result;
    static int res_append;

    static class Point{
        int x;
        int y;
        Point(int x,int y){
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        map = new int[N][N];
        visited = new boolean[N][N];
        result = new int[N*N];

        for (int i = 0; i < N; ++i) {
            String s = sc.next();
            for (int j = 0; j < N; ++j) {
                map[i][j] = s.charAt(j)-'0';
            }
        }

        init();
        res_append = 0;
        int dong = 0;
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < N; ++x) {
                if (map[y][x] == 1 && visited[y][x] == false) {
                    dong++;
                    numberingAndCounting(x, y);
                }

            }
        }
        System.out.println(dong);
        Arrays.sort(result);
        for(int i=0;i<result.length;++i){
            if(result[i] != -1){
                System.out.println(result[i]);
            }
        }
    }


    static void numberingAndCounting(int x,int y){
        Queue<Point> q = new LinkedList<>();
        q.offer(new Point(x,y));
        int cnt = 1;
        visited[y][x] = true;

        while(!q.isEmpty()){
            Point pos = q.poll();

            for(int cur=0;cur<4;++cur){
                int nx = dx[cur] + pos.x;
                int ny = dy[cur] + pos.y;

                if(nx<0 || ny <0 || nx>=N || ny>=N) continue;
                if(map[ny][nx] == 1 && visited[ny][nx] == false){
                    ++cnt;
                   // System.out.println( "("+ny + "," + nx+")" + "--" + cnt);
                    q.offer(new Point(nx,ny));
                    visited[ny][nx] = true;
                }

            }
        }
        //System.out.println();
        //System.out.println(cnt);
        result[res_append] = cnt;
        res_append++;
    }

    static void init(){
        for(int i=0;i<visited.length;++i){
            Arrays.fill(visited[i],false);
        }
        Arrays.fill(result,-1);
    }


}

