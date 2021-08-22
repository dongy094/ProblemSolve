package com.javalec.ex;
import java.util.*;
class Solution {
    public String solution(int[][] scores) {
        StringBuffer sb = new StringBuffer();
        int n = scores.length;

        for(int x=0;x<n;++x){
            int avg = 0;
            int num = n;
            int max = -1;
            int min = 999;
            int mine = scores[x][x];
            boolean flag = true;
            int sum = 0;
            for(int y=0;y<n;++y){
                int cur = scores[y][x];
                if(mine == cur && x!=y){
                    flag = false;
                }
                sum += scores[y][x];
                max = Math.max(scores[y][x],max);
                min = Math.min(scores[y][x],min);
            }

            if(flag && (mine==max || mine==min)){
                sum -= mine;
                num--;
            }

            avg = sum / num;
            if(avg>=90) sb.append("A");
            else if(avg>=80) sb.append("B");
            else if(avg>=70) sb.append("C");
            else if(avg>=50) sb.append("D");
            else sb.append("F");
        }   

        return sb.toString();
    }
}