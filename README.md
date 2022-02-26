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

Project develop for <a href="https://www.42sp.org.br/"> <img src="https://github.com/LucasDatilioCarderelli/42Cursus/blob/master/img/42-saopaulo.png" height=50> </a>

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
This is a **C** project for build a **API** server that returns some infos of **Cryptocurrency** like Bitcoin, Etherium and [GODS](https://godsunchained.com/) requesting from [*Mercado Bitcoin*](https://www.mercadobitcoin.com.br/), a brazillian exchange with a public api. To see the documentation click [**here**](https://www.mercadobitcoin.com.br/api-doc/), to see others publics API's check this [repository](https://github.com/public-apis/public-apis).

## Prerequisites

### ``mongoose``
* [respository](https://github.com/cesanta/mongoose)
* [documentation](https://mongoose.ws/documentation/#user-guide)
> Used for create a server in localhost:8000.

### ``get_next_line``
* [repository](https://github.com/LucasDatilioCarderelli/01-Get_next_line)
> Used for parse the log file in cli

### ``libcurl``
* [documantation](https://curl.se/libcurl/c/libcurl.html)
> Used for request a external api and this local api.

## How to Execute

```bash
$> make all
```
> Compile all objects and executables.

```bash
$> ./api_server
```
> Execute the api server in the terminal.

```bash
$> ./get_log
```
> Show the summary of the Log file.

## Routes
```
\
\BTC
\ETH
\BAT
\GODS
```

Output
```json
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