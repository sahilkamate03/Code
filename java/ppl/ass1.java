public class ass1 {
    
    public static int findLength(String str) {
        return str.length();
    }
    
    public static boolean compareStrings(String str1, String str2) {
        return str1.equals(str2);
    }
    
    public static char extractCharacter(String str, int index) {
        if (index >= 0 && index < str.length()) {
            return str.charAt(index);
        } else {
            throw new IndexOutOfBoundsException("Index out of range.");
        }
    }
    
    public static void main(String[] args) {
        String str1 = "I am Sahil!";
        String str2 = "I am Sahil";
        int index = 5;
        
        boolean areEqual = compareStrings(str1, str2);
        System.out.println("Are str1 and str2 equal? " + areEqual);

                
        int length = findLength(str1);
        System.out.println("Length of str1: " + length);
        
        char extractedChar = extractCharacter(str1, index);
        System.out.println("Character at index " + index + " in str1: " + extractedChar);
    }
}
