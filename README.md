<div align="center">

```bash
╔═══════════════════════════════════║═║═══════════╗
║██╗ ██╗ ██████╗ ██╗       ███╗   ██████╗  ██████╗║
║██║ ██║     ██║ ██║      █████╗  ██║ ║██╗ ██╔═══╝║
║██████║ ██████║ ██║     ██   ██╗ █████╔═╝ ██████╗║
║    ██║ ██╔═══╝ ██║     ███████║ ██║ ║██╗     ██║║
║    ██║ ██████╗ ██████╗ ██║  ██║ ██████╔╝ ██████║║
║    ╚═╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝ ╚═║═║═╝  ╚═════╝║
╚═════════════════════════════════════════════════╝
```

Project development for <a href="https://www.42sp.org.br/"> <img src="https://github.com/LucasDatilioCarderelli/42Cursus/blob/master/img/42-saopaulo.png" height=50> </a>

</div>

<p align="center">
  	<a href="https://www.linkedin.com/in/lucasdatiliocarderelli/">
    	<img alt="Linkedin" src="https://img.shields.io/badge/Lucas Datilio Carderelli-blue?style=flat&logo=Linkedin&logoColor=white" />
  	</a>
	<a href="https://github.com/LucasDatilioCarderelli" alt="login intra">
    	<img src="https://img.shields.io/badge/-ldatilio-gray?style=flat&logo=42&logoColor=white" />
	</a>
	<br>
</p>

## Description
This is a **C** project for building an **API** server that returns some infos of **Cryptocurrency** like Bitcoin, Etherium and [GODS](https://godsunchained.com/) requesting from [*Mercado Bitcoin*](https://www.mercadobitcoin.com.br/), a Brazilian exchange with a public API. To see the documentation click [**here**](https://www.mercadobitcoin.com.br/api-doc/), to see other public APIs check this [repository](https://github.com/public-apis/public-apis).

## Table of content

* [Prerequisites](#prerequisites)
* [How to Execute](#how-to-execute)
* [How to test the CLI](#how-to-test-the-cli)
* [API Requests](#api-requests)
* [License](#license)
* [What to do next](#what-to-do-next)
	* [Contact](#contact)

## Prerequisites

### ``mongoose``
* [respository](https://github.com/cesanta/mongoose)
* [documentation](https://mongoose.ws/documentation/#user-guide)
> Used for create a server in localhost:8000.

### ``get_next_line``
* [repository](https://github.com/LucasDatilioCarderelli/01-Get_next_line)
> Used for parse the log file in cli.

### ``libcurl``
* [documantation](https://curl.se/libcurl/c/libcurl.html)
> Used for request a external API and this local API.

## How to Execute

To run this project is recommendable to execute the Makefile to create the API server and the CLI binaries.
```bash
$> make all
```
> Compile all objects and executables.

To run the server, execute the program below.
```bash
$> ./run_api
```
> Executes the API server in the terminal.

## How to test the CLI

Execute the command below to see some information and analytics data of the project.
```bash
$> ./my_cli

Options avaliable:
║
╠══ version:    Show Mongoose Version.
╠══ endpoints:  List all coins supported.
╚══ show:       Show the log's summary.

```

Exemple:
```bash
$> ./my_cli show

╔══════════════╦═══════════════╦═══════════════╗
║Total Requests║  HTTP Method  ║      Path     ║
╠══════════════╬═══════════════╬═══════════════╣
║      17      ║      GET      ║      /        ║
║      36      ║      GET      ║      /BTC     ║
║      03      ║      GET      ║      /GODS    ║
║      54      ║     ERROR     ║       404     ║
╚══════════════╩═══════════════╩═══════════════╝
```

## API Requests

```
http://localhost:8000/{COIN}
```

<span style="color:green"> **[GET] /** <br></span>
> Header: HomePage
```json
{"CoinsAvailables":["BTC", "ETH", "BAT", "GODS"]}
```
<span style="color:green"> **[GET] /BTC** <br></span>
> Show the current Information of BTC.<br>
> Response: application/json

<span style="color:green"> **[GET] /ETH** <br></span>
> Show the current Information of ETH.<br>
> Response: application/json

<span style="color:green"> **[GET] /BAT** <br></span>
> Show the current Information of BAT.<br>
> Response: application/json

<span style="color:green"> **[GET] /GODS** <br></span>
> Show the current Information of GODS.<br>
> Response: application/json


<span style="color:green">**[OK] 200 Response**</span>

```JSON
{
	"ticker": {
		"high": "208000.00000000",
		"low": "196120.88525000",
		"vol": "58.44889346",
		"last": "205851.25000001",
		"buy": "205851.25000000",
		"sell": "205851.25000001",
		"open": "198591.00223001",
		"date": 1645839553
	}
}
```

<span style="color:red">**[KO] 404 Response**</span>

```JSON
{
	"message":"Page not Found"
}
```

## License

This project is under the [GNU General Public License v3](LICENSE).

## What to do next

* Implement automatized tests and CI/CD pipelines with Github Actions.
* Configure a docker environment.
* Create a Database to store the requests responses.
* Add more functionalities for the CLI and treat the log.

Reference used for this project: [link](https://melodic-walker-f2c.notion.site/42LABS-ae348f7bc8e240cf97651785cfc22467)

---

>> thanks to:
<a href="https://github.com/Vinicius-Santoro" alt="login intra">
    <img src="https://img.shields.io/badge/-vnazioze-gray?style=flat&logo=42&logoColor=white" />
</a>
<a href="https://github.com/edubona8" alt="login intra">
    <img src="https://img.shields.io/badge/-ebonamic-gray?style=flat&logo=42&logoColor=white" />
</a>
<a href="https://github.com/maykonmori" alt="login intra">
    <img src="https://img.shields.io/badge/-mjose--ye-gray?style=flat&logo=42&logoColor=white" />
</a>
to support me.

### Contact:

<a href="https://github.com/LucasDatilioCarderelli" alt="login intra">
    <img src="https://img.shields.io/badge/-ldatilio-gray?style=flat&logo=42&logoColor=white" />
</a>
<a href="https://www.linkedin.com/in/lucasdatiliocarderelli/">
    <img alt="Linkedin" src="https://img.shields.io/badge/Lucas Datilio Carderelli-blue?style=flat&logo=Linkedin&logoColor=white" />
</a>
