/*
 * iso639-2 language codes
 */
#if defined(WIN32) || defined(WIN64)
#include "../win32/config.h"
#endif
#include <string.h>
#include "iso639_2.h"

typedef struct {
	const char *code1;
	const char *code2;
	unsigned char main;
	const char *language;
} iso639_2_t;

static iso639_2_t iso639_2[] = {
	{ "abk", "",    1, "Abkhazian" },
	{ "ace", "",    1, "Achenese" },
	{ "ace", "",    1, "Achinese" },
	{ "ach", "",    1, "Acoli" },
	{ "ada", "",    1, "Adangme" },
	{ "ady", "",    1, "Adygei" },
	{ "ady", "",    1, "Adyghe" },
	{ "aar", "",    1, "Afar" },
	{ "afh", "",    1, "Afrihili" },
	{ "afr", "",    1, "Afrikaans" },
	{ "afa", "",    1, "Afroasiatic languages" },
	{ "ain", "",    1, "Ainu" },
	{ "aka", "",    1, "Akan" },
	{ "akk", "",    1, "Akkadian" },
	{ "alb", "sqi", 1, "Albanian" },
	{ "gsw", "",    1, "Alemannic" },
	{ "ale", "",    1, "Aleut" },
	{ "alg", "",    1, "Algonquian languages" },
	{ "gsw", "",    1, "Alsatian" },
	{ "alt", "",    1, "Altai, Southern" },
	{ "tut", "",    1, "Altaic languages" },
	{ "amh", "",    1, "Amharic" },
	{ "egy", "",    1, "Ancient Egyptian" },
	{ "grc", "",    1, "Ancient Greek" },
	{ "anp", "",    1, "Angika" },
	{ "apa", "",    1, "Apache languages" },
	{ "arc", "",    1, "Aramaic, Imperial" },
	{ "arc", "",    1, "Aramaic, Official" },
	{ "arp", "",    1, "Arapaho" },
	{ "arw", "",    1, "Arawak" },
	{ "arg", "",    1, "Argonese" },
	{ "arm", "hye", 1, "Armenian" },
	{ "rup", "",    1, "Aromanian" },
	{ "art", "",    1, "Artificial languages" },
	{ "rup", "",    1, "Arumanian" },
	{ "asm", "",    1, "Assamese" },
	{ "ast", "",    1, "Asturian" },
	{ "ast", "",    1, "Asturleonese" },
	{ "ath", "",    1, "Athabaskan languages" },
	{ "aus", "",    1, "Australian languages" },
	{ "map", "",    1, "Austronesian languages" },
	{ "ava", "",    1, "Avaric" },
	{ "ave", "",    1, "Avestan" },
	{ "awa", "",    1, "Awadhi" },
	{ "aze", "",    1, "Azerbaijani" },
	{ "ast", "",    1, "Bable" },
	{ "ban", "",    1, "Balinese" },
	{ "bat", "",    1, "Baltic languages" },
	{ "bal", "",    1, "Baluchi" },
	{ "bam", "",    1, "Bambara" },
	{ "bai", "",    1, "Bamileke languages" },
	{ "bad", "",    1, "Banda languages" },
	{ "bnt", "",    1, "Bantu languages" },
	{ "bas", "",    1, "Basa" },
	{ "bak", "",    1, "Bashkir" },
	{ "baq", "eus", 1, "Basque" },
	{ "bej", "",    1, "Bedawiyet" },
	{ "bej", "",    1, "Beja" },
	{ "bel", "",    1, "Belarusian" },
	{ "bem", "",    1, "Bemba" },
	{ "ben", "",    1, "Bengali" },
	{ "ber", "",    1, "Berber languages" },
	{ "bho", "",    1, "Bhojpuri" },
	{ "bih", "",    1, "Bihari languages" },
	{ "bik", "",    1, "Bikol" },
	{ "byn", "",    1, "Bilin" },
	{ "bin", "",    1, "Bini" },
	{ "bis", "",    1, "Bislama" },
	{ "bla", "",    1, "Blackfoot" },
	{ "byn", "",    1, "Blin" },
	{ "zbl", "",    1, "Blissymbols" },
	{ "bos", "",    1, "Bosnian" },
	{ "bra", "",    1, "Braj" },
	{ "btk", "",    1, "Bratak languages" },
	{ "bre", "",    1, "Breton" },
	{ "bug", "",    1, "Buginese" },
	{ "bul", "",    1, "Bulgarian" },
	{ "bua", "",    1, "Buriat" },
	{ "bur", "mya", 1, "Burmese" },
	{ "cad", "",    1, "Caddo" },
	{ "spa", "",    0, "Castilian" },
	{ "cat", "",    1, "Catalan" },
	{ "cau", "",    1, "Caucasian languages" },
	{ "ceb", "",    1, "Cebuano" },
	{ "cel", "",    1, "Celtic languages" },
	{ "cai", "",    1, "Central American Indian languages" },
	{ "khm", "",    1, "Central Khmer" },
	{ "chg", "",    1, "Chagatai" },
	{ "cmc", "",    1, "Chamic languages" },
	{ "cha", "",    1, "Chamorro" },
	{ "che", "",    1, "Chechen" },
	{ "chr", "",    1, "Cherokee" },
	{ "nya", "",    1, "Chewa" },
	{ "chy", "",    1, "Cheyenne" },
	{ "chb", "",    1, "Chibcha" },
	{ "nya", "",    1, "Chichewa" },
	{ "chi", "zho", 1, "Chinese" },
	{ "chn", "",    1, "Chinook Jargon" },
	{ "chp", "",    1, "Chipewyan" },
	{ "cho", "",    1, "Choctaw" },
	{ "zha", "",    1, "Chuang" },
	{ "chu", "",    1, "Church Slavic" },
	{ "chu", "",    1, "Church Slavonic" },
	{ "chk", "",    1, "Chuukese" },
	{ "chv", "",    1, "Chuvash" },
	{ "kbd", "",    1, "Circassian" },
	{ "nwc", "",    1, "Classical Nepal Bhasa" },
	{ "nwc", "",    1, "Classical Newari" },
	{ "syc", "",    1, "Classical Syriac" },
	{ "rar", "",    1, "Cook Islands Maori" },
	{ "cop", "",    1, "Coptic" },
	{ "cor", "",    1, "Cornish" },
	{ "cos", "",    1, "Corsican" },
	{ "cre", "",    1, "Cree" },
	{ "mus", "",    1, "Creek" },
	{ "crp", "",    1, "creoles and pidgins" },
	{ "cpe", "",    1, "creoles and pidgins, English-based" },
	{ "cpf", "",    1, "creoles and pidgins, French-based" },
	{ "cpp", "",    1, "creoles and pidgins, Portuguese-based" },
	{ "crh", "",    1, "Crimean Tartar" },
	{ "crh", "",    1, "Crimean Turkish" },
	{ "hrv", "",    1, "Croatian" },
	{ "cus", "",    1, "Cushitic languages" },
	{ "cze", "ces", 1, "Czech" },
	{ "dak", "",    1, "Dakota" },
	{ "dan", "",    1, "Danish" },
	{ "dar", "",    1, "Dargwa" },
	{ "del", "",    1, "Delaware" },
	{ "chp", "",    1, "Dene Suline" },
	{ "div", "",    1, "Dhivehi" },
	{ "din", "",    1, "Dinka" },
	{ "div", "",    1, "Divehi" },
	{ "doi", "",    1, "Dogri" },
	{ "dgr", "",    1, "Dogrib" },
	{ "dra", "",    1, "Dravidian languages" },
	{ "dua", "",    1, "Duala" },
	{ "dut", "",    1, "Dutch" },
	{ "dum", "",    1, "Dutch, Middle" },
	{ "dyu", "",    1, "Dyula" },
	{ "dzo", "",    1, "Dzongkha" },
	{ "frs", "",    1, "Eastern Frisian" },
	{ "bin", "",    1, "Edo" },
	{ "efi", "",    1, "Efik" },
	{ "egy", "",    1, "Egyptian (Ancient)" },
	{ "eka", "",    1, "Ekajuk" },
	{ "elx", "",    1, "Elamite" },
	{ "eng", "",    1, "English" },
	{ "enm", "",    0, "English, Middle" },
	{ "ang", "",    0, "English, Old" },
	{ "myv", "",    1, "Erzya" },
	{ "epo", "",    1, "Esperanto" },
	{ "est", "",    1, "Estonian" },
	{ "ewe", "",    1, "Ewe" },
	{ "ewo", "",    1, "Ewondo" },
	{ "fan", "",    1, "Fang" },
	{ "fat", "",    1, "Fanti" },
	{ "fao", "",    1, "Faroese" },
	{ "fij", "",    1, "Fijian" },
	{ "fil", "",    1, "Filipino" },
	{ "fin", "",    1, "Finnish" },
	{ "fiu", "",    1, "Finno-Ugric languages" },
	{ "dut", "",    1, "Flemish" },
	{ "fon", "",    1, "Fon" },
	{ "fre", "fra", 1, "French" },
	{ "frm", "",    0, "French, Middle" },
	{ "fro", "",    0, "French, Old" },
	{ "frs", "",    1, "Frisian, Eastern" },
	{ "frr", "",    1, "Frisian, Northern" },
	{ "fry", "",    1, "Frisian, Western" },
	{ "fur", "",    1, "Friulian" },
	{ "ful", "",    1, "Fulah" },
	{ "gaa", "",    1, "Ga" },
	{ "gla", "",    1, "Gaelic" },
	{ "car", "",    1, "Galibi Carib" },
	{ "lug", "",    1, "Ganda" },
	{ "gay", "",    1, "Gayo" },
	{ "gba", "",    1, "Gbaya" },
	{ "gez", "",    1, "Ge'ez" },
	{ "geo", "kat", 1, "Georgian" },
	{ "ger", "deu", 1, "German" },
	{ "nds", "",    1, "German, Low" },
	{ "gmh", "",    1, "German, Middle High" },
	{ "goh", "",    1, "German, Old High" },
	{ "gem", "",    1, "Germanic languages" },
	{ "kik", "",    1, "Gikuyu" },
	{ "gil", "",    1, "Gilbertese" },
	{ "gon", "",    1, "Gondi" },
	{ "gor", "",    1, "Gorontalo" },
	{ "got", "",    1, "Gothic" },
	{ "grb", "",    1, "Grebo" },
	{ "grc", "",    1, "Greek, Ancient" },
	{ "gre", "ell", 1, "Greek, Modern" },
	{ "kal", "",    1, "Greenlandic" },
	{ "grn", "",    1, "Guarani" },
	{ "guj", "",    1, "Gujarati" },
	{ "gwi", "",    1, "Gwich'in" },
	{ "hai", "",    1, "Haida" },
	{ "hat", "",    1, "Haitian" },
	{ "hat", "",    1, "Haitian Creole" },
	{ "hau", "",    1, "Hausa" },
	{ "haw", "",    1, "Hawaiian" },
	{ "heb", "",    1, "Hebrew" },
	{ "hil", "",    1, "Hiligaynon" },
	{ "him", "",    1, "Himachali languages" },
	{ "hin", "",    1, "Hindi" },
	{ "hmo", "",    1, "Hiri Motu" },
	{ "hit", "",    1, "Hittite" },
	{ "hmn", "",    1, "Hmong" },
	{ "hun", "",    1, "Hungarian" },
	{ "hup", "",    1, "Hupa" },
	{ "iba", "",    1, "Iban" },
	{ "ice", "isl", 1, "Icelandic" },
	{ "ido", "",    1, "Ido" },
	{ "ibo", "",    1, "Igbo" },
	{ "ijo", "",    1, "Ijo languages" },
	{ "ilo", "",    1, "Iloko" },
	{ "arc", "",    1, "Imperial Aramaic" },
	{ "smn", "",    1, "Inari Sami" },
	{ "inc", "",    1, "Indic languages" },
	{ "ine", "",    1, "Indo-European languages" },
	{ "ind", "",    1, "Indonesian" },
	{ "inh", "",    1, "Ingush" },
	{ "ina", "",    1, "Interlingua" },
	{ "ile", "",    1, "Interlingue, Occidental" },
	{ "iku", "",    1, "Inuktitut" },
	{ "ipk", "",    1, "Inupiaq" },
	{ "ira", "",    1, "Iranian languages" },
	{ "mga", "",    1, "Irish, Middle" },
	{ "sga", "",    1, "Irish, Old" },
	{ "iro", "",    1, "Iroquoian languages" },
	{ "ita", "",    1, "Italian" },
	{ "jpn", "",    1, "Japanese" },
	{ "jav", "",    1, "Javanese" },
	{ "kac", "",    1, "Jingpho" },
	{ "jrb", "",    1, "Judaeo-Arabic" },
	{ "jpr", "",    1, "Judaeo-Persian" },
	{ "kab", "",    1, "Kabyle" },
	{ "kac", "",    1, "Kachin" },
	{ "kal", "",    1, "Kalaallisut" },
	{ "xal", "",    1, "Kalmyk" },
	{ "kam", "",    1, "Kamba" },
	{ "kan", "",    1, "Kannada" },
	{ "kau", "",    1, "Kanuri" },
	{ "pam", "",    1, "Kapampangan" },
	{ "kaa", "",    1, "Kara-Kalpak" },
	{ "krc", "",    1, "Karachay-Balkar" },
	{ "krl", "",    1, "Karelian" },
	{ "kar", "",    1, "Karen languages" },
	{ "kas", "",    1, "Kashmiri" },
	{ "csb", "",    1, "Kashubian" },
	{ "kaw", "",    1, "Kawi" },
	{ "kaz", "",    1, "Kazakh" },
	{ "kha", "",    1, "Khasi" },
	{ "khi", "",    1, "Khoisan languages" },
	{ "kho", "",    1, "Khotanese" },
	{ "kik", "",    1, "Kikuyu" },
	{ "kmb", "",    1, "Kimbundu" },
	{ "kin", "",    1, "Kinyarwanda" },
	{ "kir", "",    1, "Kirghiz" },
	{ "gil", "",    1, "Kiribati" },
	{ "tlh", "",    1, "Klingon" },
	{ "kom", "",    1, "Komi" },
	{ "kon", "",    1, "Kongo" },
	{ "kok", "",    1, "Konkani" },
	{ "kor", "",    1, "Korean" },
	{ "kos", "",    1, "Kosraean" },
	{ "kpe", "",    1, "Kpelle" },
	{ "kro", "",    1, "Kru languages" },
	{ "kua", "",    1, "Kuanyama" },
	{ "kum", "",    1, "Kumyk" },
	{ "kur", "",    1, "Kurdish" },
	{ "kru", "",    1, "Kurukh" },
	{ "kut", "",    1, "Kutenai" },
	{ "kua", "",    1, "Kwanyama" },
	{ "kir", "",    1, "Kyrgyz" },
	{ "lad", "",    1, "Ladino" },
	{ "lah", "",    1, "Lahnda" },
	{ "lam", "",    1, "Lamba" },
	{ "day", "",    1, "Land Dayak languages" },
	{ "lao", "",    1, "Lao" },
	{ "lat", "",    1, "Latin" },
	{ "lav", "",    1, "Latvian" },
	{ "ast", "",    1, "Leonese" },
	{ "ltz", "",    1, "Letzeburgesch" },
	{ "lez", "",    1, "Lezghian" },
	{ "lim", "",    1, "Limburgan" },
	{ "lim", "",    1, "Limburger" },
	{ "lim", "",    1, "Limburgish" },
	{ "lin", "",    1, "Lingala" },
	{ "lit", "",    1, "Lithuanian" },
	{ "jbo", "",    1, "Lojban" },
	{ "nds", "",    1, "Low German" },
	{ "nds", "",    1, "Low Saxon" },
	{ "dsb", "",    1, "Lower Sorbian" },
	{ "loz", "",    1, "Lozi" },
	{ "lub", "",    1, "Luba-Katanga" },
	{ "lua", "",    1, "Luba-Lulua" },
	{ "lui", "",    1, "Luiseno" },
	{ "smj", "",    1, "Lule Sami" },
	{ "lun", "",    1, "Lunda" },
	{ "luo", "",    1, "Luo" },
	{ "luo", "",    1, "Luo (Kenya and Tanzania)" },
	{ "lus", "",    1, "Lushai" },
	{ "ltz", "",    1, "Luxembourgish" },
	{ "mas", "",    1, "Maasai" },
	{ "rup", "",    1, "Macedo-Romanian" },
	{ "mac", "mkd", 1, "Macedonian" },
	{ "mad", "",    1, "Madurese" },
	{ "mag", "",    1, "Magahi" },
	{ "mai", "",    1, "Maithili" },
	{ "mak", "",    1, "Makasar" },
	{ "mlg", "",    1, "Malagasy" },
	{ "may", "msa", 1, "Malay" },
	{ "mal", "",    1, "Malayalam" },
	{ "div", "",    1, "Maldivian" },
	{ "mlt", "",    1, "Maltese" },
	{ "mnc", "",    1, "Manchu" },
	{ "mdr", "",    1, "Mandar" },
	{ "man", "",    1, "Mandingo" },
	{ "mni", "",    1, "Manipuri" },
	{ "mno", "",    1, "Manobo languages" },
	{ "glv", "",    1, "Manx" },
	{ "mao", "mri", 1, "Maori" },
	{ "arn", "",    1, "Mapuche" },
	{ "arn", "",    1, "Mapudungun" },
	{ "mar", "",    1, "Marathi" },
	{ "chm", "",    1, "Mari" },
	{ "mah", "",    1, "Marshallese" },
	{ "mwr", "",    1, "Marwari" },
	{ "myn", "",    1, "Mayan languages" },
	{ "men", "",    1, "Mende" },
	{ "mic", "",    1, "Mi'kmaq" },
	{ "mic", "",    1, "Micmac" },
	{ "dum", "",    1, "Middle Dutch" },
	{ "enm", "",    1, "Middle English" },
	{ "frm", "",    1, "Middle French" },
	{ "gmh", "",    1, "Middle High German" },
	{ "mga", "",    1, "Middle Irish" },
	{ "pal", "",    1, "Middle Persian" },
	{ "min", "",    1, "Minangkabau" },
	{ "mwl", "",    1, "Mirandese" },
	{ "gre", "ell", 1, "Modern Greek" },
	{ "moh", "",    1, "Mohawk" },
	{ "mdf", "",    1, "Moksha" },
	{ "mkh", "",    1, "Mon-Khmer languages" },
	{ "lol", "",    1, "Mongo" },
	{ "mon", "",    1, "Mongolian" },
	{ "mos", "",    1, "Mossi" },
	{ "mul", "",    1, "Multiple languages" },
	{ "mun", "",    1, "Munda languages" },
	{ "nqo", "",    1, "N'Ko" },
	{ "nah", "",    1, "Nahuatl" },
	{ "nau", "",    1, "Nauruan" },
	{ "nav", "",    1, "Navaho" },
	{ "nav", "",    1, "Navajo" },
	{ "ndo", "",    1, "Ndonga" },
	{ "nap", "",    1, "Neapolitan" },
	{ "new", "",    1, "Nepal Bhasa" },
	{ "nep", "",    1, "Nepali" },
	{ "new", "",    1, "Newari" },
	{ "nia", "",    1, "Nias" },
	{ "nic", "",    1, "Niger-Congo languages" },
	{ "ssa", "",    1, "Nilo-Saharan languages" },
	{ "niu", "",    1, "Niuean" },
	{ "nog", "",    1, "Nogai" },
	{ "non", "",    0, "Norse, Old" },
	{ "nai", "",    1, "North American Indian languages" },
	{ "frr", "",    1, "Northern Frisian" },
	{ "nde", "",    1, "Northern Ndebele" },
	{ "sme", "",    1, "Northern Sami" },
	{ "nso", "",    1, "Northern Sotho" },
	{ "nob", "",    1, "Norwegian Bokmaal" },
	{ "nno", "",    1, "Norwegian Nynorsk" },
	{ "zxx", "",    1, "Not linguistic content; not applicable" },
	{ "nub", "",    1, "Nubian languages" },
	{ "iii", "",    1, "Nuosu" },
	{ "nym", "",    1, "Nyamwezi" },
	{ "nya", "",    1, "Nyanja" },
	{ "nyn", "",    1, "Nyankole" },
	{ "nyr", "",    1, "Nyoro" },
	{ "nzi", "",    1, "Nzima" },
	{ "oci", "",    1, "Occitan" },
	{ "pro", "",    0, "Occitan, Old" },
	{ "arc", "",    1, "Official Aramaic" },
	{ "xal", "",    1, "Oirat" },
	{ "oji", "",    1, "Ojibwa" },
	{ "chu", "",    1, "Old Bulgarian" },
	{ "chu", "",    1, "Old Church Slavonic" },
	{ "ang", "",    1, "Old English" },
	{ "fro", "",    1, "Old French" },
	{ "goh", "",    1, "Old High German" },
	{ "sga", "",    1, "Old Irish" },
	{ "nwc", "",    1, "Old Newari" },
	{ "non", "",    1, "Old Norse" },
	{ "pro", "",    1, "Old Occitan" },
	{ "peo", "",    1, "Old Persian" },
	{ "pro", "",    1, "Old Provencal" },
	{ "chu", "",    1, "Old Slavonic" },
	{ "ori", "",    1, "Oriya" },
	{ "orm", "",    1, "Oromo" },
	{ "osa", "",    1, "Osage" },
	{ "oss", "",    1, "Ossetian" },
	{ "oss", "",    1, "Ossetic" },
	{ "oto", "",    1, "Otomian languages" },
	{ "ota", "",    1, "Ottoman Turkish" },
	{ "pal", "",    1, "Pahlavi" },
	{ "pau", "",    1, "Palauan" },
	{ "pli", "",    1, "Pali" },
	{ "pam", "",    1, "Pampanga" },
	{ "pag", "",    1, "Pangasinan" },
	{ "pan", "",    1, "Panjabi" },
	{ "pap", "",    1, "Papiamento" },
	{ "paa", "",    1, "Papuan languages" },
	{ "pus", "",    1, "Pashto" },
	{ "pus", "",    1, "Pashto language" },
	{ "nso", "",    1, "Pedi" },
	{ "per", "fas", 1, "Persian" },
	{ "pal", "",    0, "Persian, Middle" },
	{ "peo", "",    0, "Persian, Old" },
	{ "phi", "",    1, "Philippine languages" },
	{ "phn", "",    1, "Phoenician" },
	{ "fil", "",    0, "Pilipino" },
	{ "pon", "",    1, "Pohnpeian" },
	{ "pol", "",    1, "Polish" },
	{ "por", "",    1, "Portuguese" },
	{ "pra", "",    1, "Prakit" },
	{ "pro", "",    0, "Provencal, Old" },
	{ "pan", "",    1, "Punjabi" },
	{ "que", "",    1, "Quechua" },
	{ "raj", "",    1, "Rajasthani" },
	{ "rap", "",    1, "Rapanui" },
	{ "rar", "",    1, "Rarotongan" },
	{ "roa", "",    1, "Romance languages" },
	{ "rum", "ron", 1, "Romanian" },
	{ "roh", "",    1, "Romansh" },	
	{ "rom", "",    1, "Romany" },
	{ "run", "",    1, "Rundi" },
	{ "rus", "",    1, "Russian" },
	{ "kho", "",    1, "Sakan" },
	{ "sal", "",    1, "Salishan languages" },
	{ "sam", "",    1, "Samaritan Aramaic" },
	{ "smi", "",    1, "Sami languages" },
	{ "smo", "",    1, "Samoan" },
	{ "sad", "",    1, "Sandawe" },
	{ "sag", "",    1, "Sango" },
	{ "san", "",    1, "Sanskrit" },
	{ "sat", "",    1, "Santali" },
	{ "srd", "",    1, "Sardinian" },
	{ "sas", "",    1, "Sasak" },
	{ "nds", "",    1, "Saxon, Low" },
	{ "sco", "",    1, "Scots" },
	{ "gla", "",    1, "Scottish Gaelic" },
	{ "sel", "",    1, "Selkup" },
	{ "sem", "",    1, "Semitic languages" },
	{ "nso", "",    1, "Sepedi" },
	{ "srp", "",    1, "Serbian" },
	{ "srr", "",    1, "Serer" },
	{ "shn", "",    1, "Shan" },
	{ "sna", "",    1, "Shona" },
	{ "iii", "",    1, "Sichuan Yi" },
	{ "scn", "",    1, "Sicilian" },
	{ "sid", "",    1, "Sidamo" },
	{ "sgn", "",    1, "Sign languages" },
	{ "bla", "",    1, "Siksika" },
	{ "snd", "",    1, "Sindhi" },
	{ "sin", "",    1, "Sinhala" },
	{ "sin", "",    1, "Sinhalese" },
	{ "sit", "",    1, "Sino-Tibetan languages" },
	{ "sio", "",    1, "Siouan languages" },
	{ "sms", "",    1, "Skolt Sami" },
	{ "den", "",    1, "Slave (Athapascan)" },
	{ "sla", "",    1, "Slavic languages" },
	{ "slo", "slk", 1, "Slovak" },
	{ "slv", "",    1, "Slovenian" },
	{ "sog", "",    1, "Sogdian" },
	{ "som", "",    1, "Somali" },
	{ "son", "",    1, "Songhay languages" },
	{ "snk", "",    1, "Soninke" },
	{ "wen", "",    1, "Sorbian languages" },
	{ "dsb", "",    1, "Sorbian, Lower" },
	{ "hsb", "",    1, "Sorbian, Upper" },
	{ "sai", "",    1, "South American Indian languages" },
	{ "alt", "",    1, "Southern Altai" },
	{ "nbl", "",    1, "Southern Ndebele" },
	{ "sma", "",    1, "Southern Sami" },
	{ "sot", "",    1, "Southern Sotho" },
	{ "spa", "",    1, "Spanish" },
	{ "srn", "",    1, "Sranan Tongo" },
	{ "zgh", "",    1, "Standard Moroccan Tamazight" },
	{ "suk", "",    1, "Sukuma" },
	{ "sux", "",    1, "Sumerian" },
	{ "sun", "",    1, "Sundanese" },
	{ "sus", "",    1, "Susu" },
	{ "swa", "",    1, "Swahili" },
	{ "ssw", "",    1, "Swati" },
	{ "swe", "",    1, "Swedish" },
	{ "gsw", "",    1, "Swiss German" },
	{ "syr", "",    1, "Syriac" },
	{ "tgl", "",    1, "Tagalog" },
	{ "tah", "",    1, "Tahitian" },
	{ "tai", "",    1, "Tai languages" },
	{ "tgk", "",    1, "Tajik" },
	{ "tmh", "",    1, "Tamashek" },
	{ "tam", "",    1, "Tamil" },
	{ "tat", "",    1, "Tatar" },
	{ "tel", "",    1, "Telugu" },
	{ "ter", "",    1, "Tereno" },
	{ "tet", "",    1, "Tetum" },
	{ "tha", "",    1, "Thai" },
	{ "tib", "bod", 1, "Tibetan" },
	{ "tig", "",    1, "Tigre" },
	{ "tir", "",    1, "Tigrinya" },
	{ "tem", "",    1, "Time" },
	{ "tiv", "",    1, "Tiv" },
	{ "tli", "",    1, "Tlingit" },
	{ "tpi", "",    1, "Tok Pisin" },
	{ "tkl", "",    1, "Tokelau" },
	{ "tog", "",    1, "Tonga (Nyasa)" },
	{ "ton", "",    1, "Tonga (Tonga Islands)" },
	{ "tsi", "",    1, "Tsimshian" },
	{ "tso", "",    1, "Tsonga" },
	{ "tsn", "",    1, "Tswana" },
	{ "tum", "",    1, "Tumbuka" },
	{ "tup", "",    1, "Tupian languages" },
	{ "tur", "",    1, "Turkish" },
	{ "ota", "",    1, "Turkish, Ottoman" },
	{ "tuk", "",    1, "Turkmen" },
	{ "tvl", "",    1, "Tuvalu" },
	{ "tyv", "",    1, "Tuvinian" },
	{ "twi", "",    1, "Twi" },
	{ "udm", "",    1, "Udmurt" },
	{ "uga", "",    1, "Ugaritic" },
	{ "uig", "",    1, "Uighur" },
	{ "ukr", "",    1, "Ukranian" },
	{ "umb", "",    1, "Umbundu" },
	{ "mis", "",    1, "Uncoded languages" },
	{ "und", "",    1, "Undetermined language" },
	{ "hsb", "",    1, "Upper Sorbian" },
	{ "urd", "",    1, "Urdu" },
	{ "uig", "",    1, "Uyghur" },
	{ "uzb", "",    1, "Uzbek" },
	{ "vai", "",    1, "Vai" },
	{ "cat", "",    1, "Valencian" },
	{ "ven", "",    1, "Venda" },
	{ "vie", "",    1, "Vietnamese" },
	{ "vol", "",    1, "Volapuk" },
	{ "vot", "",    1, "Voltic" },
	{ "wak", "",    1, "Wakashan languages" },
	{ "wln", "",    1, "Walloon" },
	{ "war", "",    1, "Waray-Waray" },
	{ "was", "",    1, "Washo" },
	{ "wel", "cym", 1, "Welsh" },
	{ "fry", "",    1, "Western Frisian" },
	{ "wal", "",    1, "Wolaitta" },
	{ "wal", "",    1, "Wolaytta" },
	{ "wol", "",    1, "Wolof" },
	{ "xho", "",    1, "Xhosa" },
	{ "sah", "",    1, "Yakut" },
	{ "yao", "",    1, "Yao" },
	{ "yap", "",    1, "Yapese" },
	{ "yid", "",    1, "Yidish" },
	{ "yor", "",    1, "Yoruba" },
	{ "ypk", "",    1, "Yupik languages" },
	{ "znd", "",    1, "Zande languages" },
	{ "zap", "",    1, "Zapotec" },
	{ "zza", "",    1, "Zaza" },
	{ "zza", "",    1, "Zazaki" },
	{ "zen", "",    1, "Zenaga" },
	{ "zha", "",    1, "Zhuang" },
	{ "zul", "",    1, "Zulu" },
	{ "zun", "",    1, "Zuni" },
};
static int niso639_2= sizeof( iso639_2 ) / sizeof( iso639_2[0] );

const char *
iso639_2_from_code( const char *code )
{
	int i;
	for ( i=0; i<niso639_2; ++i ) {
		if ( !iso639_2[i].main ) continue;
		if ( !strcasecmp( iso639_2[i].code1, code ) )
			return iso639_2[i].language;
		if ( iso639_2[i].code2[0]!='\0' && !strcasecmp( iso639_2[i].code2, code ) )
			return iso639_2[i].language;
	}
	return NULL;
}

const char *
iso639_2_from_language( const char *lang )
{
	int i, n;
	for ( i=0; i<niso639_2; ++i ) {
		n = strcasecmp( iso639_2[i].language, lang );
		if ( n==0 ) return iso639_2[i].code1;
		if ( n > 0 ) return NULL;
	}
	return NULL;
}

#ifdef TEST

#include <stdio.h>
#include <stdlib.h>

static int
check_alphabetical( void )
{
	char *l1, *l2;
	int i, ret = 1;
	l1 = iso639_2[0].language;
	for ( i=0; i<niso639_2-1; ++i ) {
		l2 = iso639_2[i+1].language;
		if ( strcasecmp( l1, l2 ) >= 0 ) {
			fprintf( stderr, "Swap '%s' and '%s'\n", l1, l2 );
			ret = 0;
		}
		l1 = l2;
	}
	return ret;
}

int
main( int argc, char *argv[] )
{
	int ok;
	ok = check_alphabetical();
	if ( ok ) return EXIT_SUCCESS;
	return EXIT_FAILURE;
}

#endif
