(* minimum missing natural number *)

(* partitioning the list around an element *)
let split x lst = 
  let aux (num, left, right) y = 
    if (y < x) then num+1, y::left, right
    else num, left, y::right
  in
  List.fold_left aux (0, [], []) lst;;

let min_missing_num lst =
  (* lo is the least nat number - 0 *) 
  let rec find_min m l = 
    match l with
    | [] -> m  (* we return 0 as the missing num *)
               (* as it is the least nat num *)
    | h::t -> 
      let (num, left, right) = split h t in
      (* if (num = h) left side is perfect *)
      (* search on the right partition *)
      if (num + m = h) then find_min (h+1) right
      else find_min m left
    in
    find_min 0 lst;;
