package com.javalec.ex;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	static int[][] map;
	static boolean[] check;
	static int N,M,V;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		M = sc.nextInt();
		V = sc.nextInt();;
		
		map = new int[1001][1001];
		check  = new boolean[1001];
		
		for(int i=0;i<M;++i) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			
			map[x][y] = map[y][x] = 1;	
		}
		
		dfs(V);
		
		check = new boolean[1001];
		System.out.println();
		
		bfs(V);
		
		
	}
	
	public static void dfs(int start) {
		
		check[start] = true;
		System.out.print(start + " ");
		
		for(int i=1;i<=N;++i) {
			if(map[i][start]==1 && check[i] == false) {
				dfs(i);
			}
		}
		
	}
	
	public static void bfs(int start) {
	
		Queue<Integer> q = new LinkedList<Integer>();
		q.offer(start);
		check[start] = true;
		System.out.print(start + " ");
		
		
		while(!q.isEmpty()) {
			int x = q.poll();
			
			for(int i=1;i<=N;++i) {
				if(check[i] == false && map[i][x] == 1) {
					check[i] = true;
					q.offer(i);
					System.out.print(i + " ");
				}
			}
			
		}
		
		
		
	}

}
	