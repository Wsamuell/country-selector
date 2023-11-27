open ReactSelect;
open CountryData;

let (>>) = (f, g, a) => g(f(a));
let options: array(CountryData.item) = [|
  {value: "one", label: "One"},
  {value: "two", label: "Two"},
  {value: "three", label: "Three"},
  {value: "four", label: "Four"},
  {value: "five", label: "Five"},
  {value: "six", label: "Six"},
  {value: "seven", label: "Seven"},
  {value: "eight", label: "Eight"},
  {value: "nine", label: "Nine"},
  {value: "ten", label: "Ten"},
|];

[@react.component]
let make = () => {
  let (countries, setCountries) = React.useState(() => parseCountry(None));
  React.useEffect1(
    () => {
      let _ =
        Js.Promise.(
          Fetch.fetch(url)
          |> then_(Fetch.Response.json)
          |> then_(json => json |> decode |> resolve)
          |> then_(itemArray => parseCountry(Some(itemArray)) |> resolve)
          |> then_(array => setCountries(_ => array) |> resolve)
        );
      Some(() => ());
    },
    [||],
  );

  <Select
    multi=false
    options=countries
    name="Country Selector"
    noResultsText="Country Not Found!"
    placeholder="Search"
  />;
};
