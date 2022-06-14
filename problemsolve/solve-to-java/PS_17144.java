package com.javalec.ex;

import java.util.Scanner;

public class Main {
	
	static int R,C,T;
	static int[][] arr = new int[50][50];	// 먼지 확산 및 공기청정기 결과용 배열
	static int cleanRow;
	static int[] pointX = {0,0,-1,1};
	static int[] pointY = {-1,1,0,0};

	public static int solve() {
		
		for(int t=0;t<T;++t) {
			int[][] spray = new int[50][50]; // 먼지 확산 계산용 배열
			// 확산(모든 배열을 거치면서 먼지가 있으면 상하좌우 확산)
			for(int i=0;i<R;++i) {
				for(int j=0;j<C;++j) {
					if(arr[i][j]<5) continue;   // 5미만은 확산되는 양이 없고, 고로 먼지의 양도 그대로 존재한다.
					int quantity = arr[i][j]/5; // 확산되는 양
					for(int k=0;k<4;++k) { 		// 상하좌우에 먼지가 확산될 수 있는지
						int nx = pointX[k] + j;
						int ny = pointY[k] + i;
						if(nx>C-1 || nx<0 || ny>R-1 || ny<0) continue; // 상하좌우 이동시 배열의 범위를 벗어나면 skip
						if(arr[ny][nx] == -1) continue; //공기청정기 일경우 skip
						spray[ny][nx] += quantity;
						spray[i][j] -= quantity;
					}
				}
			}
			
			// 확산된것을 기존 배열에 합치기
			for(int i=0;i<R;++i) {
				for(int j=0;j<C;++j) {
					arr[i][j] += spray[i][j];
				}
			}
			
			// 공기청정기 돌리기(미세먼지이동) 상
			for(int i=cleanRow-1;i>=1;--i) {
				arr[i][0] = arr[i-1][0];
			}
			for(int j=0;j<=C-2;++j) {
				arr[0][j] = arr[0][j+1];
			}
			for(int i=0;i<=cleanRow-1;++i) {
				arr[i][C-1] = arr[i+1][C-1];
			}
			for(int j=C-1;j>=2;--j) {
				arr[cleanRow][j] = arr[cleanRow][j-1];
			}
			arr[cleanRow][1] = 0;
			
			// 공기청정기 돌리기(미세먼지이동) 하
			for(int i=cleanRow+2;i<=R-2;++i) {
				arr[i][0] = arr[i+1][0];
			}
			for(int j=0;j<=C-2;j++) {
				arr[R-1][j] = arr[R-1][j+1];
			}
			for(int i=R-1;i>=cleanRow+2;--i) {
				arr[i][C-1] = arr[i-1][C-1];
			}
			for(int j=C-1;j>=2;--j) {
				arr[cleanRow+1][j] = arr[cleanRow+1][j-1];
			}
			arr[cleanRow+1][1] = 0;
		}
		
		int result = 0;
		for(int i=0;i<R;++i) {
			for(int j=0;j<C;++j) {
				if(arr[i][j] > 0) {
					result += arr[i][j];
				}
				
			}
		}
		
		return result;
	}
	
	public static void main(String[] args){
	
		Scanner sc = new Scanner(System.in);
		R = sc.nextInt();
		C = sc.nextInt();
		T = sc.nextInt();
		
		for(int i=0;i<R;++i) {
			for(int j=0;j<C;++j) {
				arr[i][j] = sc.nextInt();
				if(arr[i][j]==-1 && arr[i-1][j]==-1) {
					cleanRow = i-1; // 공기청정기 위치(상하두칸중 위에칸)
				}
			}
		}
		
		System.out.println(solve());
	}
	
}
	