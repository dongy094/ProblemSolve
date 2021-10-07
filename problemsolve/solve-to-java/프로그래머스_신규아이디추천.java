import java.util.*;
class Solution {
    boolean isVaild(char c){
        if(Character.isLetterOrDigit(c)) return true;
        if(c == '-' || c =='_' || c =='.') return true;
        return false;
    }

    public String solution(String new_id) {
        StringBuilder answer = new StringBuilder();
        boolean dotFlag = false;
        for(char ch : new_id.toCharArray()){
            ch = Character.toLowerCase(ch);
            if(isVaild(ch) == false) continue;
            if(ch == '.'){
                if(answer.length() == 0 || dotFlag) continue;
                dotFlag = true;
            }else{
                dotFlag = false;
            }
            answer.append(ch);
        }
        if(answer.length()>=16){
            answer.setLength(15);
        }
        if(answer.length()==0){
            answer.append('a');
        }
        if(answer.charAt(answer.length()-1) == '.'){
            answer.deleteCharAt(answer.length()-1);
        }
        while(answer.length()<=2){
            answer.append(answer.charAt(answer.length()-1));
        }
        return answer.toString();
    }
}