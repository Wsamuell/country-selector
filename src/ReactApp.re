open ReactSelect;
open CountryData;

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

module App = {
  [@react.component]
  let make = () => {
    React.useEffect(() => {
      let _ =
        Js.Promise.(
          Fetch.fetch(url)
          |> then_(Fetch.Response.json)
          |> then_(json => json |> decode |> resolve)
          |> then_(itemArray => fetchCountries(Some(itemArray)) |> resolve)
        );
      Some(() => ());
    });
    Js.log(fetchCountries);

    <div>
      <Select
        multi=false
        options
        name="Country Selector"
        noResultsText="Country Not Found!"
        placeholder="Search"
      />
    </div>;
  };
};

ReactDOM.querySelector("#root")
->(
    fun
    | Some(root) => ReactDOM.render(<App />, root)
    | None =>
      Js.Console.error(
        "Failed to start React: couldn't find the #root element",
      )
  );
