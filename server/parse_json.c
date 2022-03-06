/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_json.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:40:07 by ldatilio          #+#    #+#             */
/*   Updated: 2022/03/06 19:25:18 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

/* Create SQL statement */
static void	create_table(sqlite3 *db)
{
	char	*zerrmsg;
	char	*sql;
	int		rc;

	zerrmsg = 0;
	sql = "CREATE TABLE COINBOOK(" \
		"ID	INTEGER PRIMARY KEY AUTOINCREMENT," \
		"DATE		DATETIME," \
		"SELL		CHAR(20)," \
		"BUY		CHAR(20) );";
	rc = sqlite3_exec(db, sql, NULL, 0, &zerrmsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zerrmsg);
		sqlite3_free(zerrmsg);
	}
	else
	{
		fprintf(stdout, "Table created successfully\n");
	}
}

/* Create SQL statement */
static void	insert_db(sqlite3 *db,
const char *date, const char *sell, const char *buy)
{
	char	*zerrmsg;
	char	*query;
	int		rc;

	zerrmsg = 0;
	query = sqlite3_mprintf(
			"INSERT INTO COINBOOK (DATE, SELL, BUY)	\
			VALUES ('%q', '%q','%q');",
			date, sell, buy);
	rc = sqlite3_exec(db, query, NULL, 0, &zerrmsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zerrmsg);
		sqlite3_free(zerrmsg);
	}
	else
	{
		fprintf(stdout, "Records created successfully\n");
	}
	sqlite3_close(db);
}

static sqlite3	*open_db(void)
{
	sqlite3	*db;
	int		rc;

	rc = sqlite3_open("database.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return (0);
	}
	else
	{
		fprintf(stderr, "Opened database successfully\n");
	}
	create_table(db);
	return (db);
}

void	parse_json(char *body)
{
	sqlite3				*db;
	struct json_object	*parsed_json;
	struct json_object	*ticker;
	struct json_object	*date;
	struct json_object	*sell;
	struct json_object	*buy;

	parsed_json = json_tokener_parse(body);
	ticker = json_object_object_get(parsed_json, "ticker");
	json_object_object_get_ex(ticker, "date", &date);
	json_object_object_get_ex(ticker, "sell", &sell);
	json_object_object_get_ex(ticker, "buy", &buy);
	db = open_db();
	insert_db(
		db,
		json_object_get_string(date),
		json_object_get_string(sell),
		json_object_get_string(buy)
		);
}
