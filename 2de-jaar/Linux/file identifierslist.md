# Common File Identifiers (Magic Numbers)

A compact Markdown reference of common **file signatures / magic numbers** — short byte sequences at the beginning of files used to identify file types.

[Wikipedia: List of file signatures](https://en.wikipedia.org/wiki/List_of_file_signatures)

> Use these values by reading the first few bytes of a file (binary) and comparing them to the hex sequences below.

---

# 🖼️ Image formats

| File type | Magic (hex) | ASCII / notes |
|---|---:|---|
| JPEG | `FF D8 FF` | Starts with `FFD8` (ends `FF D9`) |
| PNG | `89 50 4E 47 0D 0A 1A 0A` | `‰PNG....` |
| GIF87a | `47 49 46 38 37 61` | `GIF87a` |
| GIF89a | `47 49 46 38 39 61` | `GIF89a` |
| BMP | `42 4D` | `BM` |
| TIFF (LE) | `49 49 2A 00` | `II*.` (little-endian) |
| TIFF (BE) | `4D 4D 00 2A` | `MM.*` (big-endian) |
| ICO | `00 00 01 00` | Windows icon |

---

# 🎵 Audio formats

| File type | Magic (hex) | ASCII / notes |
|---|---:|---|
| MP3 (ID3 tag) | `49 44 33` | `ID3` tag at start (frames may start with `FF FB`) |
| WAV | `52 49 46 46` ... `57 41 56 45` | `RIFF....WAVE` (RIFF container) |
| FLAC | `66 4C 61 43` | `fLaC` |
| OGG | `4F 67 67 53` | `OggS` |
| MIDI | `4D 54 68 64` | `MThd` |

---

# 🎥 Video formats / containers

| File type | Magic (hex) | ASCII / notes |
|---|---:|---|
| MP4 / MOV (ISO) | `00 00 00 ?? 66 74 79 70` | contains `ftyp` box (offsets vary) |
| AVI | `52 49 46 46` ... `41 56 49 20` | `RIFF....AVI ` |
| MKV / WebM | `1A 45 DF A3` | Matroska EBML header |
| FLV | `46 4C 56 01` | `FLV` |
| 3GP | `00 00 00 ?? 66 74 79 70 33 67` | `ftyp3g` variants |

---

# 📄 Documents / Office

| File type | Magic (hex) | ASCII / notes |
|---|---:|---|
| PDF | `25 50 44 46` | `%PDF` |
| DOC (old, OLE) | `D0 CF 11 E0 A1 B1 1A E1` | Compound File Binary (legacy MS Office) |
| DOCX / XLSX / PPTX / ZIP | `50 4B 03 04` | `PK..` (ZIP-based Office Open XML) |
| RTF | `7B 5C 72 74 66` | `{\rtf` |
| HTML | usually starts with `<` (e.g. `3C 68 74 6D 6C`) | no fixed magic number |
| XML | `3C 3F 78 6D 6C` | `<?xml` |
| JSON | starts with `{` or `[` | no magic number; detect by parsing |

---

# ⚙️ Executables / system binaries

| File type | Magic (hex) | ASCII / notes |
|---|---:|---|
| Windows EXE / DLL | `4D 5A` | `MZ` (DOS header) |
| ELF (Linux) | `7F 45 4C 46` | `\x7FELF` |
| Mach-O (macOS) | `FE ED FA CE` / `FE ED FA CF` / `CA FE BA BE` | various Mach-O headers |
| COM | none (raw binary) | typically no header |
| Batch (`.bat`) | plain ASCII text (often starts `@echo off`) | script file |

---

# 📦 Archives / compressed

| File type | Magic (hex) | ASCII / notes |
|---|---:|---|
| ZIP | `50 4B 03 04` | `PK..` |
| RAR (v1.5+) | `52 61 72 21 1A 07 00` | `Rar!..` |
| 7z | `37 7A BC AF 27 1C` | `7z..'` |
| GZ | `1F 8B` | gzip |
| BZ2 | `42 5A 68` | `BZh` |
| TAR | no single magic | identified by archive structure / metadata |

---

# 💿 Disk / image formats

| File type | Magic (hex) | ASCII / notes |
|---|---:|---|
| ISO9660 | `43 44 30 30 31` at offset `0x8001` | `CD001` |
| VHD | `63 6F 6E 65 63 74 69 78` | `conectix` (VHD footer) |
| IMG / raw | varies | raw byte-level images |

---

# 🧠 Quick usage examples

    **Command-line (hexdump)**

```bash

# show first 16 bytes
xxd -l 16 -g 1 filename

or

 hexdump -n 16 -C filename
```
