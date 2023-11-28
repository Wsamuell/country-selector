open Bindings;
open CountryData;
open Icons;

module Colors = {
  type color =
    | Light
    | Dark
    | Grey
    | Primary
    | Secondary;

  let colorToHex = (color: color) =>
    switch (color) {
    | Light => "#FFFFFF"
    | Dark => "#000000"
    | Grey => "#E5E5E5"
    | Primary => "#F2F2F2"
    | Secondary => "#F2F2F2"
    };
};
let arrowPath = "./arrow.png";
module Style = {
  open Colors;
  let wrapper =
    ReactDOM.Style.make(~width="230px", ~height="429px", ~font="Arial", ());
  let dropdown =
    ReactDOM.Style.make(~width="30%", ~color=colorToHex(Light), ());
  let selectContainer =
    ReactDOM.Style.make(~paddingTop="4px", ~paddingBottom="4px", ());
  let button =
    ReactDOM.Style.make(
      ~display="flex",
      ~height="26px",
      ~padding="4px 10px",
      ~alignItems="center",
      ~borderRadius="3px",
      ~minWidth="141px",
      ~justifyContent="space-between",
      ~border=
        "1px solid var(--light-border-control-alpha, rgba(0, 0, 0, 0.20))",
      ~background="#FFFFFF",
      (),
    );
  let flag =
    ReactDOM.Style.make(
      ~backgroundSize="contain",
      ~backgroundPosition="50%",
      ~backgroundRepeat="no-repeat",
      (),
    );
  let arrowFlip = {
    ReactDOM.Style.make(~padding="3px", ());
  };
};

[@react.component]
let make = () => {
  let (active, setActive) = React.useState(() => false);
  let (countries, setCountries) =
    React.useState(() => countryLoadState(None));
  let (selectedCountry, setSelectedCountry) =
    React.useState(() => {label: "Select A country", value: "xx"});
  React.useEffect1(
    () => {
      let _ =
        Js.Promise.(
          Fetch.fetch(url)
          |> then_(Fetch.Response.json)
          |> then_(json => json |> decode |> resolve)
          |> then_(itemArray =>
               countryLoadState(Some(itemArray)) |> resolve
             )
          |> then_(array => setCountries(_ => array) |> resolve)
        );
      Some(() => ());
    },
    [||],
  );
  <div style=Style.wrapper>
    <button onClick={_ => setActive(_ => !active)} style=Style.button>
      // <Flag countryCode={selectedCountry.value} />

        {React.string(selectedCountry.label)}
        <Arrow style=Style.arrowFlip />
      </button>
    {active
     |> (
       fun
       | true =>
         <div style=Style.selectContainer>
           <Select
             arrowRenderer={_ => React.null}
             closeMenuOnSelect=true
             multi=true
             name="Country Selector"
             noOptionsMessage={_ => "Country Not Found!"}
             onChange={value => {
               setSelectedCountry(_ => value);
               setActive(_ => false);
             }}
             options=countries
             placeholder="Search"
             styles=Style.dropdown
             wrapperStyle=Style.dropdown
           />
         </div>
       | false => React.null
     )}
  </div>;
};
