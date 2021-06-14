package com.javalec.ex;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Pair{
	int row, col;
	public Pair(int row,int col) {
		this.row = row;
		this.col = col;
	}
}


public class Main {

	static int arr[][];
	static int check[][];
	static int n,m;
	static int result;
	static int[] dx = {0,0,1,-1};
	static int[] dy = {1,-1,0,0};
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		arr = new int[n+1][m+1];
		check = new int[n+1][m+1];
		
		//input
		for(int i=1;i<=n;++i) {
			String row = br.readLine();
			for(int j=1;j<=m;++j) {
				arr[i][j] = row.charAt(j-1)-'0'; // string 1개씩 뺴내서 char형에서 숫자로 넣기위해 -0(상수)
			}
		}
		solve_bfs();
		System.out.println(check[n][m]);
	}
	
	public static void solve_bfs() {
		
		Queue<Pair> q = new LinkedList<Pair>();
		q.add(new Pair(1,1));
		check[1][1] = 1;

		while(!q.isEmpty()) {
			
			Pair tmp_pair = q.poll();
			int row = tmp_pair.row;
			int col = tmp_pair.col;
			
			for(int dir=0;dir<4;++dir) {
				int ny = row+dy[dir];
				int nx = col+dx[dir];

				if(nx<1 || ny<1 || nx>m || ny>n) continue;
				if(check[ny][nx]==0 && arr[ny][nx]==1) {
					
			
						q.add(new Pair(ny,nx));
						check[ny][nx] = check[row][col] + 1;
						
					
				}
				
			}
			
		}
		
		
		
	}
	

}
	