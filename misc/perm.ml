let rec insert x lst =
  match lst with
  | [] -> [[x]]
  | h::t -> 
    (x::lst) :: (List.map (fun el -> h::el) (insert x t));;
  
let rec perm lst =
  match lst with
  | [] -> [lst]
  | h::t -> 
    List.flatten (List.map (insert h) (perm t));;

let flatn lst =
  let rec aux acc l =
    match l with
    | [] -> acc
    | h::t -> aux (acc @ h) t
  in
  aux [] lst;;

let rec mapp f lst =
  match lst with
  | [] -> []
  | h::t -> f h :: (mapp f t);;

