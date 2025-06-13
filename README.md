# Flight Schedule Analyzer

This involves processing two common data formats:

- `airports.ini`: a list of Canadian airports with metadata.
- `departures.ics`: a calendar of long-haul flight departures.

The goal is to write a C++ program that reads these files, builds data structures, and provides useful information about scheduled flights.

---

## Files

### `airports.ini`

A configuration-style file listing airports, in sections like this:

```ini
[YYZ]
Name=Toronto Pearson International Airport
Province=Ontario
City=Mississauga
IATA_Code=YYZ
Annual_Passengers=46800000
...
```

### `departures.ics`

A calendar file with multiple events, each representing a long-haul flight:

```ics
BEGIN:VEVENT
SUMMARY:Departure from Toronto Pearson International Airport to Manila (MNL)
DTSTART:20250614T150000Z
DESCRIPTION:YYZ → MNL (long-haul route)
...
END:VEVENT
```

---

## Exercises

### File Parsing

- [ ] Read the `airports.ini` file and store the airports in a suitable data structure.
- [ ] Read the `departures.ics` file and extract flight events.
- [ ] For each flight, identify:

  - Departure airport
  - Destination IATA code
  - Departure date/time

### Data Integration

- [ ] Match each flight with its departure airport using information from `airports.ini`.
- [ ] Store the data in structures that allow for querying.

### Queries

Implement an interactive menu that allows the user to:

- [ ] List all flights departing from a given city or province.
- [ ] List all flights going to a given destination airport.
- [ ] List all flights departing on a specific date.
- [ ] Show which airport has the most long-haul departures.

### Optional Extensions

- [ ] Display flight durations.
- [ ] Output a nicely formatted flight schedule report.
- [ ] Add support for other types of queries.
