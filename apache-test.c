/*
 * Author: Jonas Raoni Soares da Silva
 * Description: Checking the inputs sent by Apache
 */

#include <stdio.h>

int main(int argc, char **argv){
	char c = fgetc(stdin), *vars[] = {
		"SERVER_SOFTWARE",
		"SERVER_NAME",
		"GATEWAY_INTERFACE",
		"SERVER_PROTOCOL",
		"SERVER_PORT",
		"REQUEST_METHOD",
		"PATH_INFO",
		"PATH_TRANSLATED",
		"SCRIPT_NAME",
		"QUERY_STRING",
		"REMOTE_HOST",
		"REMOTE_ADDR",
		"AUTH_TYPE",
		"REMOTE_USER",
		"REMOTE_IDENT",
		"CONTENT_TYPE",
		"CONTENT_LENGTH",
		"HTTP_ACCEPT",
		"HTTP_USER_AGENT",
	};
	int i = sizeof(vars) / sizeof(char *);
	printf("Content-type: text/html\n\n");
	printf("<pre><h2>[ENVIRONMENT]</h2> <br />");
	for(; i--; printf("<b>%s</b> = %s <br />", vars[i], getenv(vars[i])));
	printf("<h2>[POST DATA]</h2> <br />");
	for(; !feof(stdin); fputc(c, stdout), c = fgetc(stdin));
	printf("</pre>");
	return 0;
}
