package com.javalec.ex;

import java.util.Scanner;

public class Main {
	
	static int N;
	static int[][] arr;
    static int[] dx = {0,1,0,-1};   //��������� x �̵� ����
    static int[] dy = {-1,0,1,0};   //��������� y �̵� ����
    static int[] dc = {1,1,2,2};   // ����̵��� �� �������� �̵��ϴ� Ƚ��
    static int[][] dsx = {{-1,1,-2,-1,1,2,-1,1,0}, {-1,-1,0,0,0,0,1,1,2},    //�𷡰� ������ x����
                          {1,-1,2,1,-1,-2,1,-1,0}, {1,1,0,0,0,0,-1,-1,-2}};
    static int[][] dsy = {{1,1,0,0,0,0,-1,-1,-2},{-1,1,-2,-1,1,2,-1,1,0},    //�𷡰� ������ y����
                          {-1,-1,0,0,0,0,1,1,2},{1,-1,2,1,-1,-2,1,-1,0}};
    static int[] sandRatio ={1,1,2,7,7,2,10,10,5};
	
    static int solve(int x,int y) {
        int totalOutSand = 0;
        int curX = x;
        int curY = y;
        
    	while(true) {
    		   for(int d = 0; d<4; d++){
                   for(int moveCount = 0; moveCount<dc[d]; moveCount++){
    				//������ġ���� �̵�
                    int nx = curX+dx[d];
                    int ny = curY+dy[d];

                    if(nx<0 || ny<0 || nx>=N ||ny>=N){
                        return totalOutSand;
                    }

                    //�̵��� ��ġ�� �� �Ѹ���
                    int sandAmt = arr[nx][ny];
                    arr[nx][ny] = 0;
                    int spreadTotal = 0;
    				
    				// Ȯ��
                    for(int spread = 0; spread<9; spread++){
                        int sandX = nx + dsx[d][spread];
                        int sandY = ny + dsy[d][spread];
                        int spreadAmount = (sandAmt*sandRatio[spread])/100;

                        if(sandX<0 || sandX>=N || sandY<0 || sandY>=N){
                            totalOutSand += spreadAmount;
                        }
                        else{
                        	arr[sandX][sandY]+=spreadAmount;
                        }
                        spreadTotal+= spreadAmount;
                    }
    				
    				
                    int alphaX = nx+dx[d];
                    int alphaY = ny+dy[d];
                    int alphaAmount = sandAmt -spreadTotal;
                    if(alphaX<0 || alphaX>=N || alphaY<0|| alphaY>=N){
                        totalOutSand +=alphaAmount;
                    }
                    else{
                        arr[alphaX][alphaY] +=alphaAmount;
                    }


                    //�̵��� ��ġ�� ������ġ�� ������Ʈ
                    curX = nx;
                    curY = ny;
    			}
    		}
   			//  �� ���� �̵�Ƚ�� ����
               for(int index = 0; index<4; index++){
               	dc[index] +=2;
               }
    	}
    	
    }
    
	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		arr = new int[N][N];
		for(int y=0;y<N;++y) {
			for(int x=0;x<N;++x) {
				arr[y][x] = sc.nextInt();
			}
		}

		System.out.println(solve(N/2,N/2));
		
	}
	
}
	