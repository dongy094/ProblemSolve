package com.javalec.ex;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	
	static int INF = 987654321;
	static int N;
	static int[][] arr = new int[20][20];
	static int[] dx = {0,0,-1,1};
	static int[] dy = {1,-1,0,0};
	
	static class Point{
		int x,y,d;
		Point(int x,int y,int d){
			this.x = x;
			this.y = y;
			this.d = d;
		}
	}
	
	public static int solve(int stx,int sty) {
		int cnt = 2;
		int size = 2; // 상어 크기
		// Queue<Point> q = new LinkedList<Point>();
		Point minP = new Point(stx,sty,0);
		int result = 0;
		do {
			boolean[][] visit = new boolean[20][20];
			Queue<Point> q = new LinkedList<Point>();
			visit[minP.y][minP.x] = true;
			q.add(new Point(minP.x, minP.y, 0));
			minP.d = INF;
			
			while(!q.isEmpty()) {
				Point curr = q.poll();
				if(curr.d > minP.d) break;
				if(arr[curr.y][curr.x] > size) continue;
				if(arr[curr.y][curr.x] < size && arr[curr.y][curr.x] != 0) {
					if(curr.d < minP.d) {
						minP = curr;
					}else if(curr.d == minP.d) {
						if(curr.y<minP.y) {
							minP = curr;
						}else if(curr.y == minP.y && curr.x < minP.x) {
							minP = curr;
						}
					}
					continue;
				}
				
				for(int k=0;k<4;++k) {
					int nx = curr.x + dx[k];
					int ny = curr.y + dy[k];
					if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
					if(visit[ny][nx]) continue;
					visit[ny][nx] = true;
					q.add(new Point(nx,ny,curr.d+1));
				}
			}
			
			if(minP.d != INF) {
				result += minP.d;
				cnt--;
				if(cnt==0) {
					 size++;
					 cnt = size;
				}
				arr[minP.y][minP.x] = 0;
			}
			
			
		}while(minP.d!=INF);
		
		return result;
	}
	
	public static void main(String[] args){
		
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		int stx=0,sty = 0;
		for(int y=0;y<N;++y) {
			for(int x=0;x<N;++x) {
				arr[y][x] = sc.nextInt();
				if(arr[y][x] == 9) {
					stx = x;
					sty = y;
					arr[y][x] = 0;
				}
			}
		}
		System.out.println(solve(stx,sty));
		
	}
	
}
	