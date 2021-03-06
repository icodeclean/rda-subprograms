/* if_statement
 Parses strings in the language generated by the rule:
 <if_statement> -> if '(' <boolexpr> ')' <statement>
 [else <statement>]
 */
void if_statement(void) {
    if (nextToken != IF_CODE)
        error();
    else {
        lex();
        if (nextToken != LEFT_PAREN)
            error();
        else {
            lex();
            boolexpr();
            if (nextToken != RIGHT_PAREN)
                error();
            else {
                lex();
                statement();
                if (nextToken == ELSE_CODE) {
                    lex();
                    statement();
                }
            }
        }
    }
}


/* while_statement
 Parses strings in the language generated by the rule:
 <while_statement> -> while '(' <boolexpr> ')' <statement>

 */
void while_statement(void) {
    if (nextToken != WHILE_CODE)
 	    error();
    else {
        lex();
        if (nextToken != LEFT_PAREN)
 		    error();
 	    else {
 		    lex();
 		    boolexpr();
 		    if (nextToken != RIGHT_PAREN)
 			    error();
 		    else {
                lex();
		 	statement();
            }
        }
    }
}


/* for_statement
 Parses strings in the language generated by the rule:
 <for_statement> -> for '(' [expr] ';' [<boolexpr>] ';' [expr] ')' <statement>

 */
void for_statement(void) {
    if (nextToken != FOR_CODE)
 	    error();
    else {
        lex();
        if (nextToken != LEFT_PAREN)
 		    error();
 	    else {
 		    lex();
            expr();
            if (nextToken != SEMI_COLON)
 		        error();
            else {
                lex();
                boolexpr();
                if (nextToken != SEMI_COLON)
 		            error();
                else {
                    lex();
                    expr();
                    if (nextToken != RIGHT_PAREN)
 			            error();
 		            else {
                        lex();
		 	            statement();
                    }
                }
            }
        }
    }
}