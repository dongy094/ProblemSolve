import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N,M;
    static int[] heights = new int[510];

    static public int solve(int row,int col,int arr[]){

        int cnt = 0;
        for(int i=1;i<M-1;++i){
            int left = 0, right = 0;
            for(int l=0;l<i;++l){
                left = Math.max(left,arr[l]);
            }
            for(int r=i+1;r<M;++r){
                right = Math.max(right,arr[r]);
            }

            if(left>arr[i] && right>arr[i]) {
                int min_height = Math.min(left, right);
                cnt += min_height - arr[i];
            }
        }
        return cnt;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<M;++i){
            heights[i] = Integer.parseInt(st.nextToken());
        }
        System.out.println(solve(N,M,heights));
    }
}
