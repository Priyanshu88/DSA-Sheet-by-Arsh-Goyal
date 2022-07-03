class Solution {
public:

    // finding no of words possible to be fit in one line then
    // counting the number of words in the first line and their total characters
    // counting the number of spaces by formula i.e. maxWidth-total_characters_in_one_line
    // distributing spaces between each words in the line
    // fix the first and last of the word since this is fixed in any justified text at beginning and the end
    // let number of words in the middle excluding already fixed first and last = n-2, where n is the num of words in the line
    // with (n-2)+1 spaces between middle texts as one in front and other at back
    // pace between middle words = total_spaces/(n-1) here n is the number of words
    // if the division is not perfectly divisible then use (space_between_middle_words)+1 for a words and without +1 for the rest
    // a can be found using a=total_space-(n-1)*space_between_middle_words

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int line_sz = 0;
        int line_start = 0;
        int num_words = 0;
        for(int i=0;i<words.size();i++)
        {
            line_sz += words[i].size();
            if(line_sz+num_words > maxWidth) 
            {
                string justified_str = justify(words,line_start,i-1,maxWidth);
                res.push_back(justified_str);
                line_start = i'
                line_sz = 0;
                i--;
                num_words = 0;
                continue;
            }
            num_words++;
        }
        string last_str;
        for(int i=line_start;i+1<words.size();i++)
        {
            last_str += word[i];
            last_str += "  ";

        }
        int n = words.size();
        last_str += words[n-1];
        n = last_str.size();
        last_str += string(maxWidth-n,' ');
        res.push_back(last_str);
        return res;
    }

    string justify(vector<string> &words,int start, int end,int maxWidth)
    {
        string res;
        int word_size = 0;
        for(int i=start;i<=end;i++)
        {

            words_size += words[i].size();
        }

        int space = maxWidth - word_size;

        int n = (end-start) + 1;
        res += words[start];
        int space_btw;

        if(n == 1)
        {
            res += string(space,' ');
            return res;
        }

        space_btw = space/(n-1);
        int a = space-(n-1)*space_btw;

        if(a>0)
        {
            res+=string(space_btw+1,' ');
            a--;
        }
        else
        {
            res += string(space_btw,' ');
        }

        for(int i=start+1;i<end;i++)
        {
            res+=words[i];
            if(a > 0)
            {
                res += string (space_btw+1,' ');
                a--;
            }
            else
            {
                res += string(space_btw,' ');
            }
        }
        res += words[end];
        return res;

    }
};