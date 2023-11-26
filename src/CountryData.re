let url: string = "https://gist.githubusercontent.com/rusty-key/659db3f4566df459bd59c8a53dc9f71f/raw/4127f9550ef063121c564025f6d27dceeb279623/counties.json";

type t = {
  label: string,
  value: string,
};

type state =
  | Loading
  | Failure
  | Success(list(t));

let countries: list(t) = [];

module Fetcher = {
  let decode = json => {
    open! Json.Decode;
    {
      label: json |> field("label", string),
      value: json |> field("value", string),
    };
  };

  let api =
    Js.Promise.(
      Fetch.fetch(url)
      |> then_(Fetch.Response.text)
      // |> then_(text => print_endline(text) |> resolve)
      |> then_(text => Json.parseOrRaise(text) |> resolve)
      |> then_(json => Json.Decode.array(decode, json) |> resolve)
      |> then_(list => resolve(list))
    );
};
