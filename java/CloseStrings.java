package leetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

public class CloseStrings {
	public boolean closeStrings(String word1, String word2) {
        //false if string lengths are not equal
        if(word1.length() != word2.length()) return false;
        //Maps for to store letter frequencies:
        Map<Character, Integer> map1 = new HashMap<>();
        Map<Character, Integer> map2 = new HashMap<>();
        //Counting letter frequencies:
        for(int i = 0; i < word1.length(); i++){
            map1.compute(word1.charAt(i), (key, value) -> (value == null) ? 1 : value + 1);
        }
        for(int i = 0; i < word2.length(); i++){
            map2.compute(word2.charAt(i), (key, value) -> (value == null) ? 1 : value + 1);
        }
        //Return false if both strings do not contain the same letters
        Iterator<Map.Entry<Character, Integer>> iterator1 = map1.entrySet().iterator();
        while(iterator1.hasNext()){
            Map.Entry<Character, Integer> entry1 = iterator1.next();
            if(!map2.containsKey(entry1.getKey())) return false;
        }
        //Return true if map values (frequencies) match else return false
        List<Integer> freq1 = new ArrayList<>(map1.values());
        List<Integer> freq2 = new ArrayList<>(map2.values());
        Collections.sort(freq1);
        Collections.sort(freq2);
        return(freq1.equals(freq2));
    }
}
